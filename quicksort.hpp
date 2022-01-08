#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include "partition.hpp"

template <typename T>
void quicksort(T a[], int l, int r, int (*piv)(T a[], int l, int r, bool (*cmp)(T& a, T& b)), bool (*cmp)(T& a, T& b))
{
    if (r > l)
    {
        int pivot = piv(a, l, r, cmp);
        quicksort(a, l, pivot - 1, piv, cmp);
        quicksort(a, pivot + 1, r, piv, cmp);
    }
}

#endif