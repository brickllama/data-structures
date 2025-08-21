#include "../../include/basic/dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_da_int()
{
    DynamicArray arr;

    printf("Testing da_init(&arr)...");
    da_init(&arr);
    printf("Passed");

    for (int i = 1; i <= 5; i++)
    {
        int *num = malloc(sizeof(int));
        *num = i;
        printf("Testing da_insert(&arr, %d)... ", *num);
        assert(da_insert(&arr, num) == true);
        printf("Passed\n");
    }

    printf("Testing if arr is holding 5 integers... ");
    assert(arr.size == 5);
    printf("Passed\n");

    da_display(&arr);

    const int *to_remove = arr.data[2];       // Number 3
    printf("Testing if 3 will be removed... ");
    assert(da_remove(&arr, to_remove) == true);
    printf("Passed\n");

    printf("Testing if arr.size == 4... ");
    assert(arr.size == 4);
    printf("Passed\n");

    const int fake_number = 17;
    const double dub = 17.12;
    const float flo = 123.456;
    const char ch = 'a';

    printf("Testing da_remove(&arr, 17)... ");
    assert(da_remove(&arr, &fake_number) == false);
    printf("Passed\n");

    printf("Testing da_remove(&arr, 17.12)... ");
    assert(da_remove(&arr, &dub) == false);
    printf("Passed\n");

    printf("Testing da_remove(&arr, 123.456)... ");
    assert(da_remove(&arr, &flo) == false);
    printf("Passed\n");

    printf("Testing da_remove(&arr, 'a')... ");
    assert(da_remove(&arr, &ch) == false);
    printf("Passed\n");

    printf("Testing da_destroy(&arr)... ");
    assert(da_destroy(&arr) == true);
    printf("Passed\n");

    printf("Testing if arr.size == 0... ");
    assert(arr.size == 0);
    printf("Passed\n");

    printf("Testing if arr.data == NULL... ");
    assert(arr.data == NULL);
    printf("Passed\n");
}

int main()
{
    test_da_int();
    return 0;
}