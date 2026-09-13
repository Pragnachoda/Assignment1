#include <stdio.h>
long long sumQuadratic(long long x, int n) {
    long long totalSum = 0;
    for (int i = 0; i <= n; i++) {
        long long term = 1;
        for (int j = 0; j < i; j++) {
            term *= x;
        }
        totalSum += term;
    }
    return totalSum;
}
long long sumLinear(long long x, int n) {
    long long totalSum = 0;
    long long currentTerm = 1; // x^0
    for (int i = 0; i <= n; i++) {
        totalSum += currentTerm;
        currentTerm *= x;
    }
    return totalSum;
}
long long fastPower(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}
long long sumLogarithmic(long long x, int n) {
    if (x == 1) {
        return n + 1;
    }
    return (fastPower(x, n + 1) - 1) / (x - 1);
}

int main() {
    long long x = 2;
    int n = 5;

    printf("--- Series Summation (x = %lld, n = %d) ---\n", x, n);
    printf("O(n^2)   Result: %lld\n", sumQuadratic(x, n));
    printf("O(n)     Result: %lld\n", sumLinear(x, n));
    printf("O(log n) Result: %lld\n", sumLogarithmic(x, n));

    return 0;
}