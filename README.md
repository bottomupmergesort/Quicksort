# Quicksort
Quicksort with several pivot choices and comparators


## Function Definitions

void quicksort(T a[], int l, int r, int (*pivAlg)(T a[], int l, int r, bool(*cmp)(T& a, T&b)), bool (*cmp)(T& a, T& b));
void partition(T a[], int l, int r, bool (*cmp)(T& a, T& b));
void randomPivot(T a[], int l, int r, bool (*cmp(T& a, T& b));
void medianOf3(T a[], int l, int r, bool (*cmp)(T& a, T& b));
bool isLess(T& a, T& b);
bool isMore(T& a, T& b);
void exch(T& a, T& b);




## use:

```
quicksort(<array>, <low index>, <high index>, <pivot-choosing algorithm function pointer>, <comparator function pointer>)
```

```
quicksort(array, 0, n - 1, medianOf3, isLess)
```
will sort an array of size n in non-decreasing order, using the median of 3 pivot choice & hoare partition.

```
quicksort(array, 0, n - 1, randomPivot, isMore)
```

will sort an array of size n in non-increasing order, using random pivot choice (randomized Quicksort).
