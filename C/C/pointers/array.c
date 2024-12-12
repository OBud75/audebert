#include "myArray.h"
#include <stdlib.h>
#include <stdio.h>


Array* create_array(int capacity) {
    Array* arr = (Array*)malloc(sizeof(Array));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;
    arr->data = (int*)malloc(capacity * sizeof(int));
    if (!arr->data) {
        printf("Memory allocation for data failed.\n");
        free(arr);
        return NULL;
    }
    return arr;
}

void free_array(Array* arr) {
    if (arr) {
        free(arr->data);
        free(arr);
    }
}


void display_array(Array* arr){
    printf("[");
    for (int i = 0; i < arr->size; ++i)
    {
        printf("%d, ", (*arr).data[i]);
    }
    printf("]\n");
}


void append_array(Array *arr, int n){
    if (arr->size >= arr->capacity)
    {
        // realloc
        int* new_data = (int*)realloc(arr->data, arr->capacity * sizeof(int));
        arr->capacity *= 2;
        if (!new_data){
            printf("Memory reallocation failed.\n");
            return;
        }
        arr->data = new_data;
    }
    arr->data[arr->size++] = n;
}

int pop_array(Array *arr){
    if (arr->size > 0){
        arr->size--;
        return arr->data[arr->size+1];
    }
    else{
        return 0;
    }
}