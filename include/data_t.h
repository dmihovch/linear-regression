
#ifndef DATA_T_H
#define DATA_T_H


typedef struct data_t{
    double* x_arr;
    double* y_arr;
    int allocated_size;
    int size;
} data_t;


data_t* init_allocate_data(int);
void print_data(data_t*);

#endif
