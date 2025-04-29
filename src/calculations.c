#include "../include/calculations.h"


double mean(double* arr, const int size){
    int i = 0;
    double sum = 0;
    for(;i<size; ++i, ++arr){
        sum+=*arr;
    }
    return sum/size;
}

double variance(double* arr, const int size){
    double m = mean(arr, size);
    double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(; i<size; ++i, ++arr){
        sum += square(*arr-m);
    }
    return sum*mult;
}

double covariance(double * x_arr, double * y_arr, const int size){
    double x_bar = mean(x_arr,size);
    double y_bar = mean(y_arr,size);
    double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(;i<size; ++i, ++x_arr, ++y_arr){
        sum+=(*x_arr-x_bar)*(*y_arr-y_bar);
    }
    return sum*mult;
}

double covariance_given_mean(double* x_arr, double* y_arr, const int size, double x_bar, double y_bar){
    double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(;i<size; ++i, ++x_arr, ++y_arr){
        sum+=(*x_arr-x_bar)*(*y_arr-y_bar);
    }
    return sum*mult;
}

const betas_t fit_linear_regression(double * x_arr, double * y_arr, const int size){

    double x_bar = mean(x_arr, size);
    double y_bar = mean(y_arr, size);

    betas_t b;
    b.b1 = covariance_given_mean(x_arr, y_arr, size, x_bar, y_bar) / variance(x_arr,size);
    b.b0 = y_bar - (b.b1 * x_bar);
    return b;
}

double predict(const betas_t b, double x){
    return b.b0 + (b.b1*x);
}

double square(double x){
    return x*x;
}
