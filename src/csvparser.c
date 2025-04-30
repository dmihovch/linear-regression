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
    if(mode > 0){
        return parse(data_raw,mode);
    }
    return parse(data_raw,DEFAULT);
}

data_t* parse(const FILE* data_raw, const int mode){
    data_t* d = init_allocate_data(mode);
    if(d == NULL){
        fclose((FILE*)data_raw);
        return NULL;
    }
    int allocate_arrays_ret_code = allocate_arrays(d, data_raw);
    return d;
}
