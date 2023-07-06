#include "bsearch_int_const.h"

#define len(x) (int)(sizeof x / sizeof *x)

int dprintf(int, char const*, ...);
#define expect(x) if (!(x)) dprintf(2, "expect(%s)\n", #x), __builtin_trap()

static _Bool lt_int_const(int const *x, int const *y, void *ctx) {
    (void)ctx;
    return *x < *y;
}

int main(void) {
    int const arr[] = { 1,3,7,9,13,17,23,41,99,1004 };

    for (int i = 0; i < len(arr); i++) {
        expect(bsearch_int_const(arr,len(arr), arr+i, lt_int_const, (void*)0) == arr+i);

        int const lo = arr[i] - 1,
                  hi = arr[i] + 1;
        expect(bsearch_int_const(arr,len(arr), &lo, lt_int_const, (void*)0) == arr+i  );
        expect(bsearch_int_const(arr,len(arr), &hi, lt_int_const, (void*)0) == arr+i+1);
    }

    return 0;
}
