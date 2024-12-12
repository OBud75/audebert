#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Array {
    int size;
    int capacity;
    int* data; 
} Array;


Array* create_array(int capacity);
void free_array();
void display_array(Array* arr);
void append_array(Array *arr, int n);
int pop_array(Array *arr);

#endif 