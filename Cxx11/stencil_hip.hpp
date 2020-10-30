#include "hip/hip_runtime.h"
__global__ void star1(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (1 <= i) && (i < n-1) && (1 <= j) && (j < n-1) ) {
            out[i*n+j] += +in[(i)*n+(j-1)] * -0.5
                          +in[(i-1)*n+(j)] * -0.5
                          +in[(i+1)*n+(j)] * 0.5
                          +in[(i)*n+(j+1)] * 0.5;
     }
}

__global__ void star2(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (2 <= i) && (i < n-2) && (2 <= j) && (j < n-2) ) {
            out[i*n+j] += +in[(i)*n+(j-2)] * -0.125
                          +in[(i)*n+(j-1)] * -0.25
                          +in[(i-2)*n+(j)] * -0.125
                          +in[(i-1)*n+(j)] * -0.25
                          +in[(i+1)*n+(j)] * 0.25
                          +in[(i+2)*n+(j)] * 0.125
                          +in[(i)*n+(j+1)] * 0.25
                          +in[(i)*n+(j+2)] * 0.125;
     }
}

__global__ void star3(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (3 <= i) && (i < n-3) && (3 <= j) && (j < n-3) ) {
            out[i*n+j] += +in[(i)*n+(j-3)] * -0.05555555555555555
                          +in[(i)*n+(j-2)] * -0.08333333333333333
                          +in[(i)*n+(j-1)] * -0.16666666666666666
                          +in[(i-3)*n+(j)] * -0.05555555555555555
                          +in[(i-2)*n+(j)] * -0.08333333333333333
                          +in[(i-1)*n+(j)] * -0.16666666666666666
                          +in[(i+1)*n+(j)] * 0.16666666666666666
                          +in[(i+2)*n+(j)] * 0.08333333333333333
                          +in[(i+3)*n+(j)] * 0.05555555555555555
                          +in[(i)*n+(j+1)] * 0.16666666666666666
                          +in[(i)*n+(j+2)] * 0.08333333333333333
                          +in[(i)*n+(j+3)] * 0.05555555555555555;
     }
}

__global__ void star4(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (4 <= i) && (i < n-4) && (4 <= j) && (j < n-4) ) {
            out[i*n+j] += +in[(i)*n+(j-4)] * -0.03125
                          +in[(i)*n+(j-3)] * -0.041666666666666664
                          +in[(i)*n+(j-2)] * -0.0625
                          +in[(i)*n+(j-1)] * -0.125
                          +in[(i-4)*n+(j)] * -0.03125
                          +in[(i-3)*n+(j)] * -0.041666666666666664
                          +in[(i-2)*n+(j)] * -0.0625
                          +in[(i-1)*n+(j)] * -0.125
                          +in[(i+1)*n+(j)] * 0.125
                          +in[(i+2)*n+(j)] * 0.0625
                          +in[(i+3)*n+(j)] * 0.041666666666666664
                          +in[(i+4)*n+(j)] * 0.03125
                          +in[(i)*n+(j+1)] * 0.125
                          +in[(i)*n+(j+2)] * 0.0625
                          +in[(i)*n+(j+3)] * 0.041666666666666664
                          +in[(i)*n+(j+4)] * 0.03125;
     }
}

__global__ void star5(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (5 <= i) && (i < n-5) && (5 <= j) && (j < n-5) ) {
            out[i*n+j] += +in[(i)*n+(j-5)] * -0.02
                          +in[(i)*n+(j-4)] * -0.025
                          +in[(i)*n+(j-3)] * -0.03333333333333333
                          +in[(i)*n+(j-2)] * -0.05
                          +in[(i)*n+(j-1)] * -0.1
                          +in[(i-5)*n+(j)] * -0.02
                          +in[(i-4)*n+(j)] * -0.025
                          +in[(i-3)*n+(j)] * -0.03333333333333333
                          +in[(i-2)*n+(j)] * -0.05
                          +in[(i-1)*n+(j)] * -0.1
                          +in[(i+1)*n+(j)] * 0.1
                          +in[(i+2)*n+(j)] * 0.05
                          +in[(i+3)*n+(j)] * 0.03333333333333333
                          +in[(i+4)*n+(j)] * 0.025
                          +in[(i+5)*n+(j)] * 0.02
                          +in[(i)*n+(j+1)] * 0.1
                          +in[(i)*n+(j+2)] * 0.05
                          +in[(i)*n+(j+3)] * 0.03333333333333333
                          +in[(i)*n+(j+4)] * 0.025
                          +in[(i)*n+(j+5)] * 0.02;
     }
}

__global__ void grid1(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (1 <= i) && (i < n-1) && (1 <= j) && (j < n-1) ) {
            out[i*n+j] += +in[(i-1)*n+(j-1)] * -0.25
                          +in[(i)*n+(j-1)] * -0.25
                          +in[(i-1)*n+(j)] * -0.25
                          +in[(i+1)*n+(j)] * 0.25
                          +in[(i)*n+(j+1)] * 0.25
                          +in[(i+1)*n+(j+1)] * 0.25
                          ;
     }
}

__global__ void grid2(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (2 <= i) && (i < n-2) && (2 <= j) && (j < n-2) ) {
            out[i*n+j] += +in[(i-2)*n+(j-2)] * -0.0625
                          +in[(i-1)*n+(j-2)] * -0.020833333333333332
                          +in[(i)*n+(j-2)] * -0.020833333333333332
                          +in[(i+1)*n+(j-2)] * -0.020833333333333332
                          +in[(i-2)*n+(j-1)] * -0.020833333333333332
                          +in[(i-1)*n+(j-1)] * -0.125
                          +in[(i)*n+(j-1)] * -0.125
                          +in[(i+2)*n+(j-1)] * 0.020833333333333332
                          +in[(i-2)*n+(j)] * -0.020833333333333332
                          +in[(i-1)*n+(j)] * -0.125
                          +in[(i+1)*n+(j)] * 0.125
                          +in[(i+2)*n+(j)] * 0.020833333333333332
                          +in[(i-2)*n+(j+1)] * -0.020833333333333332
                          +in[(i)*n+(j+1)] * 0.125
                          +in[(i+1)*n+(j+1)] * 0.125
                          +in[(i+2)*n+(j+1)] * 0.020833333333333332
                          +in[(i-1)*n+(j+2)] * 0.020833333333333332
                          +in[(i)*n+(j+2)] * 0.020833333333333332
                          +in[(i+1)*n+(j+2)] * 0.020833333333333332
                          +in[(i+2)*n+(j+2)] * 0.0625
                          ;
     }
}

__global__ void grid3(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (3 <= i) && (i < n-3) && (3 <= j) && (j < n-3) ) {
            out[i*n+j] += +in[(i-3)*n+(j-3)] * -0.027777777777777776
                          +in[(i-2)*n+(j-3)] * -0.005555555555555556
                          +in[(i-1)*n+(j-3)] * -0.005555555555555556
                          +in[(i)*n+(j-3)] * -0.005555555555555556
                          +in[(i+1)*n+(j-3)] * -0.005555555555555556
                          +in[(i+2)*n+(j-3)] * -0.005555555555555556
                          +in[(i-3)*n+(j-2)] * -0.005555555555555556
                          +in[(i-2)*n+(j-2)] * -0.041666666666666664
                          +in[(i-1)*n+(j-2)] * -0.013888888888888888
                          +in[(i)*n+(j-2)] * -0.013888888888888888
                          +in[(i+1)*n+(j-2)] * -0.013888888888888888
                          +in[(i+3)*n+(j-2)] * 0.005555555555555556
                          +in[(i-3)*n+(j-1)] * -0.005555555555555556
                          +in[(i-2)*n+(j-1)] * -0.013888888888888888
                          +in[(i-1)*n+(j-1)] * -0.08333333333333333
                          +in[(i)*n+(j-1)] * -0.08333333333333333
                          +in[(i+2)*n+(j-1)] * 0.013888888888888888
                          +in[(i+3)*n+(j-1)] * 0.005555555555555556
                          +in[(i-3)*n+(j)] * -0.005555555555555556
                          +in[(i-2)*n+(j)] * -0.013888888888888888
                          +in[(i-1)*n+(j)] * -0.08333333333333333
                          +in[(i+1)*n+(j)] * 0.08333333333333333
                          +in[(i+2)*n+(j)] * 0.013888888888888888
                          +in[(i+3)*n+(j)] * 0.005555555555555556
                          +in[(i-3)*n+(j+1)] * -0.005555555555555556
                          +in[(i-2)*n+(j+1)] * -0.013888888888888888
                          +in[(i)*n+(j+1)] * 0.08333333333333333
                          +in[(i+1)*n+(j+1)] * 0.08333333333333333
                          +in[(i+2)*n+(j+1)] * 0.013888888888888888
                          +in[(i+3)*n+(j+1)] * 0.005555555555555556
                          +in[(i-3)*n+(j+2)] * -0.005555555555555556
                          +in[(i-1)*n+(j+2)] * 0.013888888888888888
                          +in[(i)*n+(j+2)] * 0.013888888888888888
                          +in[(i+1)*n+(j+2)] * 0.013888888888888888
                          +in[(i+2)*n+(j+2)] * 0.041666666666666664
                          +in[(i+3)*n+(j+2)] * 0.005555555555555556
                          +in[(i-2)*n+(j+3)] * 0.005555555555555556
                          +in[(i-1)*n+(j+3)] * 0.005555555555555556
                          +in[(i)*n+(j+3)] * 0.005555555555555556
                          +in[(i+1)*n+(j+3)] * 0.005555555555555556
                          +in[(i+2)*n+(j+3)] * 0.005555555555555556
                          +in[(i+3)*n+(j+3)] * 0.027777777777777776
                          ;
     }
}

__global__ void grid4(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (4 <= i) && (i < n-4) && (4 <= j) && (j < n-4) ) {
            out[i*n+j] += +in[(i-4)*n+(j-4)] * -0.015625
                          +in[(i-3)*n+(j-4)] * -0.002232142857142857
                          +in[(i-2)*n+(j-4)] * -0.002232142857142857
                          +in[(i-1)*n+(j-4)] * -0.002232142857142857
                          +in[(i)*n+(j-4)] * -0.002232142857142857
                          +in[(i+1)*n+(j-4)] * -0.002232142857142857
                          +in[(i+2)*n+(j-4)] * -0.002232142857142857
                          +in[(i+3)*n+(j-4)] * -0.002232142857142857
                          +in[(i-4)*n+(j-3)] * -0.002232142857142857
                          +in[(i-3)*n+(j-3)] * -0.020833333333333332
                          +in[(i-2)*n+(j-3)] * -0.004166666666666667
                          +in[(i-1)*n+(j-3)] * -0.004166666666666667
                          +in[(i)*n+(j-3)] * -0.004166666666666667
                          +in[(i+1)*n+(j-3)] * -0.004166666666666667
                          +in[(i+2)*n+(j-3)] * -0.004166666666666667
                          +in[(i+4)*n+(j-3)] * 0.002232142857142857
                          +in[(i-4)*n+(j-2)] * -0.002232142857142857
                          +in[(i-3)*n+(j-2)] * -0.004166666666666667
                          +in[(i-2)*n+(j-2)] * -0.03125
                          +in[(i-1)*n+(j-2)] * -0.010416666666666666
                          +in[(i)*n+(j-2)] * -0.010416666666666666
                          +in[(i+1)*n+(j-2)] * -0.010416666666666666
                          +in[(i+3)*n+(j-2)] * 0.004166666666666667
                          +in[(i+4)*n+(j-2)] * 0.002232142857142857
                          +in[(i-4)*n+(j-1)] * -0.002232142857142857
                          +in[(i-3)*n+(j-1)] * -0.004166666666666667
                          +in[(i-2)*n+(j-1)] * -0.010416666666666666
                          +in[(i-1)*n+(j-1)] * -0.0625
                          +in[(i)*n+(j-1)] * -0.0625
                          +in[(i+2)*n+(j-1)] * 0.010416666666666666
                          +in[(i+3)*n+(j-1)] * 0.004166666666666667
                          +in[(i+4)*n+(j-1)] * 0.002232142857142857
                          +in[(i-4)*n+(j)] * -0.002232142857142857
                          +in[(i-3)*n+(j)] * -0.004166666666666667
                          +in[(i-2)*n+(j)] * -0.010416666666666666
                          +in[(i-1)*n+(j)] * -0.0625
                          +in[(i+1)*n+(j)] * 0.0625
                          +in[(i+2)*n+(j)] * 0.010416666666666666
                          +in[(i+3)*n+(j)] * 0.004166666666666667
                          +in[(i+4)*n+(j)] * 0.002232142857142857
                          +in[(i-4)*n+(j+1)] * -0.002232142857142857
                          +in[(i-3)*n+(j+1)] * -0.004166666666666667
                          +in[(i-2)*n+(j+1)] * -0.010416666666666666
                          +in[(i)*n+(j+1)] * 0.0625
                          +in[(i+1)*n+(j+1)] * 0.0625
                          +in[(i+2)*n+(j+1)] * 0.010416666666666666
                          +in[(i+3)*n+(j+1)] * 0.004166666666666667
                          +in[(i+4)*n+(j+1)] * 0.002232142857142857
                          +in[(i-4)*n+(j+2)] * -0.002232142857142857
                          +in[(i-3)*n+(j+2)] * -0.004166666666666667
                          +in[(i-1)*n+(j+2)] * 0.010416666666666666
                          +in[(i)*n+(j+2)] * 0.010416666666666666
                          +in[(i+1)*n+(j+2)] * 0.010416666666666666
                          +in[(i+2)*n+(j+2)] * 0.03125
                          +in[(i+3)*n+(j+2)] * 0.004166666666666667
                          +in[(i+4)*n+(j+2)] * 0.002232142857142857
                          +in[(i-4)*n+(j+3)] * -0.002232142857142857
                          +in[(i-2)*n+(j+3)] * 0.004166666666666667
                          +in[(i-1)*n+(j+3)] * 0.004166666666666667
                          +in[(i)*n+(j+3)] * 0.004166666666666667
                          +in[(i+1)*n+(j+3)] * 0.004166666666666667
                          +in[(i+2)*n+(j+3)] * 0.004166666666666667
                          +in[(i+3)*n+(j+3)] * 0.020833333333333332
                          +in[(i+4)*n+(j+3)] * 0.002232142857142857
                          +in[(i-3)*n+(j+4)] * 0.002232142857142857
                          +in[(i-2)*n+(j+4)] * 0.002232142857142857
                          +in[(i-1)*n+(j+4)] * 0.002232142857142857
                          +in[(i)*n+(j+4)] * 0.002232142857142857
                          +in[(i+1)*n+(j+4)] * 0.002232142857142857
                          +in[(i+2)*n+(j+4)] * 0.002232142857142857
                          +in[(i+3)*n+(j+4)] * 0.002232142857142857
                          +in[(i+4)*n+(j+4)] * 0.015625
                          ;
     }
}

__global__ void grid5(const int n, const prk_float * in, prk_float * out) {
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const int j = blockIdx.y * blockDim.y + threadIdx.y;
    if ( (5 <= i) && (i < n-5) && (5 <= j) && (j < n-5) ) {
            out[i*n+j] += +in[(i-5)*n+(j-5)] * -0.01
                          +in[(i-4)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-3)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-2)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-1)*n+(j-5)] * -0.0011111111111111111
                          +in[(i)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+1)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+2)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+3)*n+(j-5)] * -0.0011111111111111111
                          +in[(i+4)*n+(j-5)] * -0.0011111111111111111
                          +in[(i-5)*n+(j-4)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-4)] * -0.0125
                          +in[(i-3)*n+(j-4)] * -0.0017857142857142857
                          +in[(i-2)*n+(j-4)] * -0.0017857142857142857
                          +in[(i-1)*n+(j-4)] * -0.0017857142857142857
                          +in[(i)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+1)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+2)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+3)*n+(j-4)] * -0.0017857142857142857
                          +in[(i+5)*n+(j-4)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-3)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-3)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-3)] * -0.016666666666666666
                          +in[(i-2)*n+(j-3)] * -0.0033333333333333335
                          +in[(i-1)*n+(j-3)] * -0.0033333333333333335
                          +in[(i)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+1)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+2)*n+(j-3)] * -0.0033333333333333335
                          +in[(i+4)*n+(j-3)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-3)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-2)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-2)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-2)] * -0.0033333333333333335
                          +in[(i-2)*n+(j-2)] * -0.025
                          +in[(i-1)*n+(j-2)] * -0.008333333333333333
                          +in[(i)*n+(j-2)] * -0.008333333333333333
                          +in[(i+1)*n+(j-2)] * -0.008333333333333333
                          +in[(i+3)*n+(j-2)] * 0.0033333333333333335
                          +in[(i+4)*n+(j-2)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-2)] * 0.0011111111111111111
                          +in[(i-5)*n+(j-1)] * -0.0011111111111111111
                          +in[(i-4)*n+(j-1)] * -0.0017857142857142857
                          +in[(i-3)*n+(j-1)] * -0.0033333333333333335
                          +in[(i-2)*n+(j-1)] * -0.008333333333333333
                          +in[(i-1)*n+(j-1)] * -0.05
                          +in[(i)*n+(j-1)] * -0.05
                          +in[(i+2)*n+(j-1)] * 0.008333333333333333
                          +in[(i+3)*n+(j-1)] * 0.0033333333333333335
                          +in[(i+4)*n+(j-1)] * 0.0017857142857142857
                          +in[(i+5)*n+(j-1)] * 0.0011111111111111111
                          +in[(i-5)*n+(j)] * -0.0011111111111111111
                          +in[(i-4)*n+(j)] * -0.0017857142857142857
                          +in[(i-3)*n+(j)] * -0.0033333333333333335
                          +in[(i-2)*n+(j)] * -0.008333333333333333
                          +in[(i-1)*n+(j)] * -0.05
                          +in[(i+1)*n+(j)] * 0.05
                          +in[(i+2)*n+(j)] * 0.008333333333333333
                          +in[(i+3)*n+(j)] * 0.0033333333333333335
                          +in[(i+4)*n+(j)] * 0.0017857142857142857
                          +in[(i+5)*n+(j)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+1)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+1)] * -0.0017857142857142857
                          +in[(i-3)*n+(j+1)] * -0.0033333333333333335
                          +in[(i-2)*n+(j+1)] * -0.008333333333333333
                          +in[(i)*n+(j+1)] * 0.05
                          +in[(i+1)*n+(j+1)] * 0.05
                          +in[(i+2)*n+(j+1)] * 0.008333333333333333
                          +in[(i+3)*n+(j+1)] * 0.0033333333333333335
                          +in[(i+4)*n+(j+1)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+1)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+2)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+2)] * -0.0017857142857142857
                          +in[(i-3)*n+(j+2)] * -0.0033333333333333335
                          +in[(i-1)*n+(j+2)] * 0.008333333333333333
                          +in[(i)*n+(j+2)] * 0.008333333333333333
                          +in[(i+1)*n+(j+2)] * 0.008333333333333333
                          +in[(i+2)*n+(j+2)] * 0.025
                          +in[(i+3)*n+(j+2)] * 0.0033333333333333335
                          +in[(i+4)*n+(j+2)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+2)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+3)] * -0.0011111111111111111
                          +in[(i-4)*n+(j+3)] * -0.0017857142857142857
                          +in[(i-2)*n+(j+3)] * 0.0033333333333333335
                          +in[(i-1)*n+(j+3)] * 0.0033333333333333335
                          +in[(i)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+1)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+2)*n+(j+3)] * 0.0033333333333333335
                          +in[(i+3)*n+(j+3)] * 0.016666666666666666
                          +in[(i+4)*n+(j+3)] * 0.0017857142857142857
                          +in[(i+5)*n+(j+3)] * 0.0011111111111111111
                          +in[(i-5)*n+(j+4)] * -0.0011111111111111111
                          +in[(i-3)*n+(j+4)] * 0.0017857142857142857
                          +in[(i-2)*n+(j+4)] * 0.0017857142857142857
                          +in[(i-1)*n+(j+4)] * 0.0017857142857142857
                          +in[(i)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+1)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+2)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+3)*n+(j+4)] * 0.0017857142857142857
                          +in[(i+4)*n+(j+4)] * 0.0125
                          +in[(i+5)*n+(j+4)] * 0.0011111111111111111
                          +in[(i-4)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-3)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-2)*n+(j+5)] * 0.0011111111111111111
                          +in[(i-1)*n+(j+5)] * 0.0011111111111111111
                          +in[(i)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+1)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+2)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+3)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+4)*n+(j+5)] * 0.0011111111111111111
                          +in[(i+5)*n+(j+5)] * 0.01
                          ;
     }
}
