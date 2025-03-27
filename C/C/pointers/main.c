#include <stdio.h>
#include "array.h"

float average(int arr[], int n){
    float s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += arr[i];
    }

    return s/n;
}


void change_odd_numbers(int *arr, int n){
    for (int i = 0; i < n; ++i)
    {
        if (*(arr + i)%2 == 1)
        {
            *(arr + i) *= 2;
            // we can do this as well:
            // arr[i] *= 2;
        }
    }
}


void fizzbuzz(int n){

    for(int i=0; i<=100; i++){
        if(i%3 ==0 && i%5==0){
            printf("FizzBuzz!\n");
        }
        else if(i%3 ==0){
            printf("Fizz!\n");
        }
        else if(i%5 ==0){
            printf("Buzz\n");
        }
        else{
            printf("%d\n",i);
        }
    }
}


int main() {
    // faire :
    // get_block
    // load_block
    // free_block

    Array* arr = create_array(1);

    append_array(arr, 12);
    append_array(arr, 2);
    append_array(arr, 3);
    append_array(arr, 3);
    append_array(arr, 3);
    pop_array(arr);
    display_array(arr);

    printf("%d\n", arr->capacity);

    free_array(arr);

    return 0;
}
