#ifndef PROJECT_EULER_STUDY_MODINT_H
#define PROJECT_EULER_STUDY_MODINT_H
#include "PEBasic.h"
template <int64_t MOD> struct Modint {
    int64_t val;
    Modint(int64_t x = 0){
        if (x < 0) x += MOD;
        val = x % MOD;
    }
    Modint operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    Modint operator + (const Modint& r) const noexcept { return Modint(*this) += r; }
    Modint operator - (const Modint& r) const noexcept { return Modint(*this) -= r; }
    Modint operator * (const Modint& r) const noexcept { return Modint(*this) *= r; }
    Modint operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }
    Modint& operator += (const Modint& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Modint& operator -= (const Modint& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    Modint& operator *= (const Modint& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    Modint& operator /= (const Modint& r) noexcept {
        Modint p = *this;
        Modint q = r;
        return p * q.modinv();
    }
    bool operator == (const Modint& r) const noexcept {
        return this->val == r.val;
    }
    bool operator != (const Modint& r) const noexcept {
        return this->val != r.val;
    }
    friend istream& operator >> (istream& is, Modint<MOD>& x) {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend ostream& operator << (ostream& os, const Modint<MOD>& x) {
        return os << x.val;
    }
    Modint<MOD> modpow(const Modint<MOD>& r, int64_t e) noexcept {
        int64_t ans = 1;
        int64_t b = val;
        for (; e; b = (b * b) % MOD, e /= 2)
            if (e & 1) ans = (ans * b) % MOD;
        return ans;
    }
    Modint<MOD> modinv(const Modint<MOD>& r) noexcept {
        return modpow(r, MOD-2);
    }
};
#endif //PROJECT_EULER_STUDY_MODINT_H
