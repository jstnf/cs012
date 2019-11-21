#include "minFunc.h"
const int* min(const int arr[], int arrSize)
{
    if (arrSize <= 1)
    {
        return arr;
    }

    const int* rMin = min(arr, arrSize - 1);
    if (*rMin > arr[arrSize - 1])
    {
        return arr + arrSize - 1;
    }
    else
    {
        return rMin;
    }
}