#include "PEBasic.h"
#include "Modint.h"

double factorial(int n) {
    if (n == 0) return 1;
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

double binomial(int n, int m) {
    return factorial(n) / (factorial(m) * factorial(n - m));
}

template <int64_t MOD> struct Zp_combinatorics {
    using mint = Modint<MOD>;
    vector <mint> cache_factorial = {1};
    mint factorial(int n) {
        if (cache_factorial.empty()) cache_factorial.push_back(1);
        int64_t last = cache_factorial.size();
        while (last <= n) {
            cache_factorial.push_back((last++) * cache_factorial.back());
        }
        return cache_factorial[n];
    }
    mint binomial(int n, int m) {
        return factorial(n) / (factorial(m) * factorial(n - m));
    }
};
