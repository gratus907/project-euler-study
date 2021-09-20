#include "../lib/PEBasic.h"

double solve() {
    double p[101], q[101];
    memset(p, 0, sizeof(p)); memset(q, 0, sizeof(q));
    p[0] = q[0] = 1;
    for (int i = 0; i < 9; i++) {
        double tmp[101]; memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j <= 36; j++) {
            for (int k = 1; k <= 4; k++) {
                tmp[j + k] += p[j] / 4;
            }
        }
        for (int j = 0; j <= 36; j++) p[j] = tmp[j];
    }
    for (int i = 0; i < 6; i++) {
        double tmp[101]; memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j <= 36; j++) {
            for (int k = 1; k <= 6; k++) {
                tmp[j + k] += q[j] / 6;
            }
        }
        for (int j = 0; j <= 36; j++) q[j] = tmp[j];
    }
    double ans = 0;
    for (int i = 36; i >= 0; i--) {
        double prob = 0;
        for (int j = i-1; j >= 0; j--) {
            prob += q[j];
        }
        ans += prob * p[i];
    }
    return ans;
}

int32_t main() {
    print_machine_info();
    timer.init();
    cout << "Answer : " << setprecision(10) << fixed << solve() << '\n';
    cout << "Solution executed in " << timer.check() << " ms\n";
}