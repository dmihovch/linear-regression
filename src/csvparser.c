#include "../include/csvparser.h"
#include <stdio.h>
#include <stdlib.h>


// if successful, will allocate memory for data_t, and both double arrays inside;
data_t* parse_csv(const char* file_path,int mode){
    FILE* data_raw = fopen(file_path, "r");
    if(data_raw == NULL){
        printf("failed to open [%s]\nreturning NULL",file_path);
        return NULL;
    }
    switch(mode){
        case DEFAULT: return default_parse(data_raw);
        /*
        case XSMALL: return mode_xsmall_parse(data_raw);
        case SMALL: return mode_small_parse(data_raw);
        case MEDIUM: return mode_medium_parse(data_raw);
        case LARGE: return mode_large_parse(data_raw);
        case XLARGE: return  mode_large_parse(data_raw);

                    todo
        */

    }
    //this should never be met;
    return default_parse(data_raw);
}

data_t* default_parse(const FILE* data_raw){
    const int mode = 10;
    data_t* d = init_allocate_data(mode);
    if(d == NULL){
        fclose((FILE*)data_raw);
        return NULL;
    }

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
                return d;
            }
        }
        char* token = strtok(line,",");
        d->x_arr[i] = strtod(token, NULL);

        token = strtok(NULL,",");
        d->y_arr[i] = strtod(token,NULL);

        i++;
    }
    fclose((FILE*)data_raw);
    return d;
}
