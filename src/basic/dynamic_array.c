#include "../../include/basic/dynamic_array.h"
#include <stdio.h>

bool da_init(DynamicArray *arr)
{
    if (arr == NULL)
        return false;

    arr->data = NULL;
    arr->size = 0;
    return true;
}

bool da_is_empty(const DynamicArray *arr)
{
    return arr->size == 0;
}

void da_display(const DynamicArray *arr)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d ", *(int *)arr->data[i]);
    }
}

bool da_insert(DynamicArray *arr, void *data)
{
    void **tmp = realloc(arr->data, (arr->size + 1) * sizeof(data));
    if (tmp == NULL && arr->size > 0)
    {
        perror("Failed to resize the array.\n");
        return false;
    }

    arr->data = tmp;
    arr->data[arr->size++] = data;
    return true;
}

bool da_remove(DynamicArray *arr, const void *data)
{
    // Look for the data to remove
    for (size_t i = 0; i < arr->size; i++)
    {
        if (arr->data[i] == data)
        {
            free(arr->data[i]);

            for (size_t j = i; j < arr->size - 1; j++)
            {
                arr->data[j] = arr->data[j + 1];
            }

            arr->size--;
            return true;
        }
    }
    return false;
}

bool da_destroy(DynamicArray *arr)
{
    if (arr == NULL)
        return false;

    for (size_t i = 0; i < arr->size; i++)
    {
        free(arr->data[i]);
    }
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    return true;
}
