#ifndef PARTITION_HPP
#define PARTITION_HPP
#include "exch.hpp"

template <typename T> 
int partition(T a[], int l, int r, bool (*cmp)(T& a, T& b));

/* comparator functions */

// (<)
template <typename T>
bool isLess(T& a, T& b)
{
    return a < b;
}

//(>)
template <typename T>
bool isMore(T& a, T& b)
{
    return a > b;
}





//Median of 3
template <typename T>
int medianOf3(T a[], int l, int r, bool (*cmp)(T& a, T& b))
{
    if (cmp (a[r], a[(r+l)/2]))
        exch(a[r], a[(r+l)/2]);

    if (cmp(a[(r+l)/2], a[l]))
        exch(a[l], a[(r+l)/2]);
    
    if (cmp(a[r], a[(r+l)/2]))
        exch(a[r], a[(r+l)/2]);

    exch(a[(r+l)/2], a[r]);
    return partition(a, l, r, cmp);
}

//Randomized Pivot
template <typename T>
int randomPivot(T a[], int l, int r, bool (*cmp)(T& a, T& b))
{
    int piv = rand() % (r - l + 1) + l;
    exch(a[piv], a[r]);
    return partition(a, l, r, cmp);
}

//default pivot a[r]
template <typename T>
int rightEl(T a[], int l, int r, bool (*cmp)(T& a, T& b))
{
    return partition(a, l, r, cmp);
}

//Hoare Partition Algorithm
template <typename T>
int partition(T a[], int l, int r, bool (*cmp)(T& a, T& b))
{
    int i = l - 1;
    int j = r;
    int pivot = a[r];
    for (;;)
    {
        while (cmp(a[++i], pivot));
        while (cmp(pivot, a[--j]));
        if (i >= j) break;
        exch(a[i], a[j]);
    }
    exch(a[i], a[r]);
    return i;
}

#endif