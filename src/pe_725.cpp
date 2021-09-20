#include "../lib/PEBasic.h"
#include "../lib/Modint.h"

const int64_t mod = 1e16;
using mint = Modint<mod>;
mint dp[2200][22][11], cnt[2200][22][11];
int64_t solve(){
    int n = 2020;
    cnt[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int d = 0; d <= 9; d++) {
            for (int a = 0; a <= 18; a++) {
                for (int b = 0; b <= 9; b++) {
                    int na = a + d; if (na >= 19) continue;
                    int nb = max(b, d);
                    cnt[i][na][nb] += cnt[i-1][a][b];
                    dp[i][na][nb] += dp[i-1][a][b] * 10 + cnt[i-1][a][b] * d;
                }
            }
        }
    }
    mint ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[n][2*i][i];
    }
    return ans.val;
}

int32_t main() {
    print_machine_info();
    timer.init();
    cout << "Answer : " << setprecision(10) << fixed << solve() << '\n';
    cout << "Solution executed in " << timer.check() << " ms\n";
}