// #include <stdio.h>

// long long A(long long x) {
//     if (x==0) return 0;
//     else return 1+A(x-1);
// }

// long long B(long long x) {
//     if (x==0) return 0;
//     else return A(x)+B(x-1);
// }

// long long C(long long x) {
//     if (x==0) return 0;
//     else return B(x)+C(x-1);
// }

// long long D(long long x) {
//     if (x==0) return 0;
//     else return C(x)+D(x-1);
// }

// int main() {
//     printf("%lld\n", D(42069));
//     return 0;
// }

// #include <stdio.h>

// long long A[42070];
// long long B[42070];
// long long C[42070];
// long long D[42070];

// void ngitung(int x) {
//     A[0] = 0;
//     B[0] = 0;
//     C[0] = 0;
//     D[0] = 0;

//     for (int i = 1; i <= x; i++) {
//         A[i] = 1 + A[i - 1];
//         B[i] = A[i] + B[i - 1];
//         C[i] = B[i] + C[i - 1];
//         D[i] = C[i] + D[i - 1];
//     }
// }

// int main() {
//     ngitung(42069);
//     printf("%lld\n", D[42069]);
//     return 0;
// }

#include <stdio.h>
int main(){

    char answer[] = "130526728149730290";
    printf("%s\n", answer);

    return 0;
}

