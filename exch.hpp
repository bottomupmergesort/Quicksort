#ifndef EXCH_HPP
#define EXCH_HPP

template <typename T>
void exch(T& A, T& B)
{
    T tmp = A;
    A = B;
    B = tmp;
}

#endif