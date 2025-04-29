#ifndef CALCULATIONS_H
#define CALCULATIONS_H




/**
   b1 = cov(x,y)/var(x)
   b0 = y(bar) - b1*x(bar)
*/
typedef struct betas_t {
    double b0; //intercept
    double b1; //slope
} betas_t;

double mean(double*,const int);
double variance(double*,const int);
double covariance(double*,double*, const int);
const betas_t fit_linear_regression(double*, double*, const int);
double predict(const betas_t, double);
double square(double);

#endif
