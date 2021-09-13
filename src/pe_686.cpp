#include "../lib/pebasic.h"

int solve() {
    double lb = log10(1.23);
    double ub = log10(1.24);
    double l2 = log10(2.00);
    int cnt = 0, ans = 0;
    double cur = 0;
    while (true) {
        ans++;
        cur = (l2 * ans);
        double u = cur - floor(cur);
        if (lb <= u and u < ub) {
            cnt++;
            if (cnt == 678910)
                return ans;
        }
    }
}

int32_t main() {
    print_machine_info();
    timer.init();
    cout << "Answer : " << solve() << '\n';
    cout << "Solution executed in " << timer.check() << " ms\n";
}