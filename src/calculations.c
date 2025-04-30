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
    const double m = mean(arr, size);
    const double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(; i<size; ++i, ++arr){
        sum += square(*arr-m);
    }
    return sum*mult;
}

double covariance(double * x_arr, double * y_arr, const int size){
    const double x_bar = mean(x_arr,size);
    const double y_bar = mean(y_arr,size);
    const double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(;i<size; ++i, ++x_arr, ++y_arr){
        sum+=(*x_arr-x_bar)*(*y_arr-y_bar);
    }
    return sum*mult;
}

double covariance_given_mean(double* x_arr, double* y_arr, const int size, double x_bar, double y_bar){
    const double mult = 1./size;
    int i = 0;
    double sum = 0;
    for(;i<size; ++i, ++x_arr, ++y_arr){
        sum+=(*x_arr-x_bar)*(*y_arr-y_bar);
    }
    return sum*mult;
}

const betas_t fit_linear_regression(double * x_arr, double * y_arr, const int size){

    const double x_bar = mean(x_arr, size);
    const double y_bar = mean(y_arr, size);

    betas_t b;
    b.b1 = covariance_given_mean(x_arr, y_arr, size, x_bar, y_bar) / variance(x_arr,size);
    b.b0 = y_bar - (b.b1 * x_bar);
    return b;
}

double r_squared(double* x_arr,double* y_arr, const betas_t b, const int size){
    return 1. - (residual_sum_of_squares(x_arr,y_arr,b,size)/total_sum_of_squares(y_arr, size));
}

double residual_sum_of_squares(double * x_arr, double * y_arr, const betas_t b, const int size){
    const double b0 = b.b0;
    const double b1 = b.b1;

    int i = 0;
    double sum = 0;
    for(; i<size; ++i,++y_arr,++x_arr){
        sum += square(*y_arr - (b0+(b1*(*x_arr))));
    }
    return sum;
}

double total_sum_of_squares(double * y_arr, const int size){
    const double y_bar = mean(y_arr,size);
    int i = 0;
    double sum = 0;
    for(; i<size;++i,++y_arr){
        sum += square(*y_arr - y_bar);
    }
    return sum;
}

double predict(const betas_t b, double x){
    return b.b0 + (b.b1*x);
}

double square(const double x){
    return x*x;
}
