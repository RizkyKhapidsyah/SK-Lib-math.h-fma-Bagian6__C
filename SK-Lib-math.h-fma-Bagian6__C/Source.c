#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    // demo perbedaan antara fma() dan operator bawaan
    double in = 0.1;
    printf("0.1 double is %.23f (%a)\n", in, in);
    printf("0.1*10 is 1.0000000000000000555112 (0x8.0000000000002p-3), or 1.0 if rounded to double\n");

    double expr_hasil = 0.1 * 10 - 1;
    printf("0.1 * 10 - 1 = %g : 1 subtracted after intermediate rounding to 1.0\n", expr_hasil);
    double fma_hasil = fma(0.1, 10, -1);
    printf("fma(0.1, 10, -1) = %g (%a)\n", fma_hasil, fma_hasil);

    // fma() digunakan dalam aritmatika ganda-ganda
    printf("\nin double-double arithmetic, 0.1 * 10 is representable as ");
    double high = 0.1 * 10;
    double low = fma(0.1, 10, -high);
    printf("%g + %g\n\n", high, low);

    //error handling / penanganan error
    feclearexcept(FE_ALL_EXCEPT);
    printf("fma(+Inf, 10, -Inf) = %f\n", fma(INFINITY, 10, -INFINITY));

    if (fetestexcept(FE_INVALID)) {
        puts("    FE_INVALID raised");
    }

    _getch();
    return 0;
}