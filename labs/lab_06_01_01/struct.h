#ifndef __STRUCT_H__
#define __STRUCT_H__

struct film_data
{
    char title[MAX_LEN];
    char name[MAX_LEN];
    int year;
};

struct film_data films[STRUCTS_AMOUNT];

#endif // __STRUCT_H__