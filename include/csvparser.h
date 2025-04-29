#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "../include/data_t.h"
#include <stdio.h>
#include <string.h>

/*
    It cracks me up how I think to define these like this. big back asl



                                put the fries in the bag bro

                                I need to change these
*/
#define DEFAULT 0
#define XSMALL 10
#define SMALL 100
#define MEDIUM 1000
#define LARGE 10000
#define XLARGE 100000


data_t* parse_csv(const char*,int);
data_t* default_parse(const FILE*);
data_t* mode_xsmall_parse(const FILE*);
data_t* mode_small_parse(const FILE*);
data_t* mode_medium_parse(const FILE*);
data_t* mode_large_parse(const FILE*);
data_t* mode_xlarge_parse(const FILE*);
int resize_arrs(data_t*);

#endif
