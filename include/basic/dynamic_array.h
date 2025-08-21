#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>    // bool
#include <stdlib.h>     // malloc, realloc, free

typedef struct
{
    void **data;            // Pointer to an array of void pointers.
    size_t size;            // The number of elements currently stored in the array.
} DynamicArray;

bool da_init(DynamicArray *arr);
bool da_is_empty(const DynamicArray *arr);
void da_display(const DynamicArray *arr);
bool da_insert(DynamicArray *arr, void *data);
bool da_remove(DynamicArray *arr, const void *data);
bool da_destroy(DynamicArray *arr);


#endif  // DYNAMIC_ARRAY_H