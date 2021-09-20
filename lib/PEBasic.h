#pragma once
#include <bits/stdc++.h>
#include <cpuid.h>
using namespace std;

using std::chrono::steady_clock;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

class Timer {
    steady_clock::time_point begin = steady_clock::now();
public:
    void init() {
        begin = steady_clock::now();
    }

    int check(bool renew = true) {
        steady_clock::time_point current = steady_clock::now();
        int ret = duration_cast<milliseconds>(current - begin).count();
        if (renew) begin = current;
        return ret;
    }
};
static Timer timer;

void print_machine_info() {
    char CPUBrandString[0x40];
    unsigned int CPUInfo[4] = {0,0,0,0};
    __cpuid(0x80000000, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
    unsigned int nExIds = CPUInfo[0];
    memset(CPUBrandString, 0, sizeof(CPUBrandString));
    for (unsigned int i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(i, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);

        if (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    cout << "CPU Type : " << CPUBrandString << '\n';
}

ostream& operator << (ostream& os, vector<int>& x) {
    os << '[';
    for (int i = 0; i < x.size(); i++) {
        os << x[i];
        os << (i+1 == x.size()?"]":", ");
    }
    return os;
}

int64_t concat(int a, int b) {
    return stoi(to_string(a) + to_string(b));
}
int64_t concat(int64_t a, int64_t b) {
    return stoi(to_string(a) + to_string(b));
}

bool find(vector<int> &v, int x) {
    return upper_bound(v.begin(), v.end(), x) == lower_bound(v.begin(), v.end(), x);
}