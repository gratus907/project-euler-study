#ifndef PROJECT_EULER_STUDY_PRIMES_H
#define PROJECT_EULER_STUDY_PRIMES_H
#include "PEBasic.h"

// Linear Sieve
vector<int> primes(int upto) {
    vector <int> result;
    vector <bool> sieve(upto+1, false);
    for (int i = 2; i <= upto; i++) {
        if (!sieve[i])
            result.push_back(i);
        for (int j : result) {
            if (i * j > upto) break;
            sieve[i * j] = true;
            if (i % j == 0) break;
        }
    }
    return result;
}

inline int64_t mulmod(int64_t x, int64_t y, int64_t m)
{
    return ((__int128)x * y % m);
}

int64_t powmod(int64_t x, int64_t y, int64_t m)
{
    x %= m;
    int64_t r = 1LL;
    while (y > 0)
    {
        if (y % 2 == 1)
            r = mulmod(r, x, m);
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

inline bool miller_rabin(int64_t n, int64_t a)
{
    int64_t d = n - 1;
    while (d % 2 == 0)
    {
        if (powmod(a, d, n) == n-1)
            return true;
        d /= 2;
    }
    int64_t tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}

bool is_prime(int64_t n)
{
    const vector<int64_t> alist ={2,3,5,7,11,13,17,19,23,29,31,37};
    if (n <= 1)
        return false;
    if (n <= 100000000LL) {
        for (int64_t i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    for (int64_t a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}
#endif //PROJECT_EULER_STUDY_PRIMES_H
