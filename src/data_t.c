#include "../include/data_t.h"


int resize_arrs(data_t* d){
    int double_size = d->allocated_size*2;
    double* tmp_x = realloc(d->x_arr,double_size*sizeof(double));
    if(tmp_x == NULL){
        return 1;
    }
    double* tmp_y = realloc(d->y_arr,double_size*sizeof(double));
    if(tmp_y == NULL){
        free(tmp_x);
        return 1;
    }
    d->x_arr = tmp_x;
    d->y_arr = tmp_y;
    d->allocated_size = double_size;
    return 0;
}

int allocate_arrays(data_t* d, const FILE* data_raw){

    char line[256];
    fgets(line,sizeof(line),(FILE*)data_raw);
    int i = 0;
    int resize_arrs_ret_code;
    while(fgets(line,sizeof(line),(FILE*)data_raw)){
        d->size+=1;
        if(d->size == d->allocated_size){
            resize_arrs_ret_code = resize_arrs(d);
            if(resize_arrs_ret_code == 1){
                printf("realloc failed, only partial data captured. recommened quit program\n");
                return 1;
            }
        }
        char* token = strtok(line,",");
        d->x_arr[i] = strtod(token, NULL);


        //todo: handle empty lines and nulls, etc

        token = strtok(NULL,",");
        d->y_arr[i] = strtod(token,NULL);

        i++;
    }
    fclose((FILE*)data_raw);
    return 0;
}

data_t* init_allocate_data(int mode){
    data_t* d = calloc(1, sizeof(data_t));
    if(d == NULL){
        return NULL;
    }
    d->x_arr = calloc(mode,sizeof(double));
    if(d->x_arr == NULL){
        free(d);
        return NULL;
    }
    d->y_arr = calloc(mode,sizeof(double));
    if(d->y_arr == NULL){
        free(d->x_arr);
        free(d);
        return NULL;
    }
    d->allocated_size = mode;
    d->size = 0;
    return d;
}

void print_data(data_t* d){
    for(int i = 0; i< d->size; i++){
        printf("%d: x: [%.3f] y: [%.3f]\n",i,d->x_arr[i],d->y_arr[i]);
    }
}
