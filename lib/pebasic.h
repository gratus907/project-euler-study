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
