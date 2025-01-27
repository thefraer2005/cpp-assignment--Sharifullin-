#include <hw04.h>
#include <iostream>
#include <cstddef> 

std::size_t hw04(const int* input_array, std::size_t elem_count) {
    std::size_t sum= 0; 
    int* out_data= new int[1]; 
    std::size_t out_size= 0; 
    for (std::size_t i = 0;i< elem_count;++i) {
        if (input_array[i] < 0) {
            break;
        }
        if (out_size> 0) 
        {
            int* new_out_data= new int[out_size + 1]; 
            for (std::size_t j=0;j<out_size; ++j) {
                new_out_data[j] =out_data[j];
            }
            new_out_data[out_size]= input_array[i];
            out_size++;
            delete[] out_data;
            out_data=new_out_data;
        } 
        else 
        {
           out_data[0]= input_array[i];
            out_size++;
        }
    }
    for (std::size_t i=0;i<out_size;++i) {
        sum+=out_data[i];
    }
    delete[] out_data;
    return sum; 
}

