!
! Copyright (c) 2015, Intel Corporation
!
! Redistribution and use in source and binary forms, with or without
! modification, are permitted provided that the following conditions
! are met:
!
! * Redistributions of source code must retain the above copyright
!       notice, this list of conditions and the following disclaimer.
! * Redistributions in binary form must reproduce the above
!       copyright notice, this list of conditions and the following
!       disclaimer in the documentation and/or other materials provided
!       with the distribution.
! * Neither the name of Intel Corporation nor the names of its
!       contributors may be used to endorse or promote products
!       derived from this software without specific prior written
!       permission.
!
! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
! LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
! FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
! COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
! INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
! BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
! LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
! CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
! LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
! ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
! POSSIBILITY OF SUCH DAMAGE.

!*******************************************************************
! NAME:    Pipeline
!
! PURPOSE: This program tests the efficiency with which point-to-point
!          synchronization can be carried out. It does so by executing
!          a pipelined algorithm on an m*n grid. The first array dimension
!          is distributed among the threads (stripwise decomposition).
!
! USAGE:   The program takes as input the
!          dimensions of the grid, and the number of iterations on the grid
!
!                <progname> <iterations> <m> <n>
!
!          The output consists of diagnostics to make sure the
!          algorithm worked, and of timing statistics.
!
! FUNCTIONS CALLED:
!
!          Other than standard C functions, the following
!          functions are used in this program:
!
! HISTORY: - Written by Rob Van der Wijngaart, February 2009.
!            Converted to Fortran by Jeff Hammond, January 2015
! *******************************************************************

program main
  use iso_fortran_env
#ifdef _OPENMP
  use omp_lib
#endif
  implicit none
  ! for argument parsing
  integer :: err
  integer :: arglen
  character(len=32) :: argtmp
  ! problem definition
  integer(kind=INT32) :: iterations                     ! number of times to run the pipeline algorithm
  integer(kind=INT32) :: m, n
  real(kind=REAL64) :: corner_val                       ! verification value at top right corner of grid
  real(kind=REAL64), allocatable :: grid(:,:)           ! array holding grid values
  ! runtime variables
  integer(kind=INT32) ::  i, j, k
  real(kind=REAL64) ::  t0, t1, pipeline_time, avgtime  ! timing parameters
  real(kind=REAL64), parameter ::  epsilon=1.D-8        ! error tolerance

  ! ********************************************************************
  ! read and test input parameters
  ! ********************************************************************

#ifndef PRKVERSION
#warning Your common/make.defs is missing PRKVERSION
#define PRKVERSION "N/A"
#endif
  write(*,'(a,a)') 'Parallel Research Kernels version ', PRKVERSION
#ifdef _OPENMP
  write(*,'(a)')   'OpenMP pipeline execution on 2D grid'
#else
  write(*,'(a)')   'Serial pipeline execution on 2D grid'
#endif

  if (command_argument_count().lt.3) then
    write(*,'(a,i1)') 'argument count = ', command_argument_count()
    write(*,'(a,a)')  'Usage: ./synch_p2p <# iterations> ',             &
                      '<first array dimension> <second array dimension>'
    stop 1
  endif

  iterations = 1
  call get_command_argument(1,argtmp,arglen,err)
  if (err.eq.0) read(argtmp,'(i32)') iterations

  m = 1
  call get_command_argument(2,argtmp,arglen,err)
  if (err.eq.0) read(argtmp,'(i32)') m

  n = 1
  call get_command_argument(3,argtmp,arglen,err)
  if (err.eq.0) read(argtmp,'(i32)') n

  if (iterations .lt. 1) then
    write(*,'(a,i5)') 'ERROR: iterations must be >= 1 : ', iterations
    stop 1
  endif

  if ((m .lt. 1).or.(n .lt. 1)) then
    write(*,'(a,i5,i5)') 'ERROR: array dimensions must be >= 1 : ', m, n
    stop 1
  endif

  allocate( grid(m,n), stat=err)
  if (err .ne. 0) then
    write(*,'(a,i3)') 'allocation of grid returned ',err
    stop 1
  endif

#ifdef _OPENMP
  write(*,'(a,i8)')    'Number of threads        = ',omp_get_max_threads()
#endif
  write(*,'(a,i8,i8)') 'Grid sizes               = ', m, n
  write(*,'(a,i8)')    'Number of iterations     = ', iterations

  !$omp parallel default(none)                                        &
  !$omp&  shared(grid,t0,t1,iterations,pipeline_time)                 &
  !$omp&  firstprivate(m,n)                                           &
  !$omp&  private(i,j,k)

  !$omp do collapse(2)
  do j=1,n
    do i=1,m
      grid(i,j) = 0.0d0
    enddo
  enddo
  !$omp end do nowait
  !$omp do
  do j=1,n
    grid(1,j) = real(j-1,REAL64)
  enddo
  !$omp end do nowait
  !$omp do
  do i=1,m
    grid(i,1) = real(i-1,REAL64)
  enddo
  !$omp end do nowait

  do k=0,iterations

    !  start timer after a warmup iteration
    !$omp barrier
    !$omp master
    if (k.eq.1) call cpu_time(t0)
    !$omp end master

    ! TODO
    !$omp master
    do j=2,n
      do i=2,m
        grid(i,j) = grid(i-1,j) + grid(i,j-1) - grid(i-1,j-1)
      enddo
    enddo
    !$omp end master

    ! copy top right corner value to bottom left corner to create dependency; we
    ! need a barrier to make sure the latest value is used. This also guarantees
    ! that the flags for the next iteration (if any) are not getting clobbered
    grid(1,1) = -grid(m,n)

  enddo ! iterations

  !$omp barrier
  !$omp master
  call cpu_time(t1)
  pipeline_time = t1 - t0
  !$omp end master

  !$omp end parallel

  ! ********************************************************************
  ! ** Analyze and output results.
  ! ********************************************************************

  ! verify correctness, using top right value
  corner_val = real((iterations+1)*(n+m-2),REAL64);
  if (abs(grid(m,n)-corner_val)/corner_val .gt. epsilon) then
    write(*,'(a,f10.2,a,f10.2)') 'ERROR: checksum ',grid(m,n), &
            ' does not match verification value ', corner_val
    stop 1
  endif

  write(*,'(a)') 'Solution validates'
  avgtime = pipeline_time/iterations
  write(*,'(a,f13.6,a,f10.6)') 'Rate (MFlop/s): ',1.e-6*2*real((m-1)*(n-1),INT64)/avgtime, &
         ' Avg time (s): ', avgtime

  deallocate( grid )

  stop

end program