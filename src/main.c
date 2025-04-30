#include "../include/calculations.h"
#include "../include/csvparser.h"
#include "../include/data_t.h"
#include <stdlib.h>

int main(int argc, char*argv[]){

    if(argc <= 1){
        printf("usage: ./lr [path_to_cvs_file] {mode}\nmodes:\n0\n10\n100\n1000\n10000\n100000\n");
        return 1;
    }
    data_t* data;
    if(argc == 2){
        printf("warning: using default mode\n");
        data = parse_csv(argv[1],0);
    }
    else{
        data = parse_csv(argv[1],atoi(argv[2]));
    }

    print_data(data);

    const betas_t b = fit_linear_regression(data->x_arr, data->y_arr, data->size);
    const double rsquared = r_squared(data->x_arr,data->y_arr,b,data->size);
    printf("beta 0: %0.9f\nbeta 1: %0.9f\n",b.b0,b.b1);
    printf("r^2: %0.9f\n",rsquared);

    free(data->x_arr);
    free(data->y_arr);
    free(data);
	return 0;
}
