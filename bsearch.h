#pragma once

#define declare_bsearch(T) \
    T* bsearch_##T(T *p, int n, T const *v, _Bool (*lt)(T const*, T const*, void*), void *ctx)

#define define_bsearch(T) \
    declare_bsearch(T) {                  \
        while (n) {                       \
            int const rem = n % 2;        \
            n /= 2;                       \
            p += (n+rem) * lt(p+n,v,ctx); \
        }                                 \
        return p;                         \
    } declare_bsearch(T)
