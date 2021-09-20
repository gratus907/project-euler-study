#include "../lib/PEBasic.h"
#include "../lib/Primes.h"

int N;
int adj[5050][5050];
int ans = INT_MAX;
vector<int> p;
void find_clique(vector<int> &cur, int target, int sum) {
    if (sum >= ans) {
        return;
    }
    if (cur.size() == target) {
        ans = min(ans, sum);
    }
    for (int i = (cur.empty()?-1:cur.back())+1; i < N; i++) {
        bool flag = true;
        for (int j : cur) {
            if (!adj[i][j]) {
                flag = false; break;
            }
        }
        if (flag) {
            cur.push_back(i);
            find_clique(cur, target, sum + p[i]);
            cur.pop_back();
        }
    }
}
int64_t solve(){
    p = primes(10000);
    int ps = p.size(); N = ps;
    for (int i = 0; i < ps; i++) {
        for (int j = i+1; j < ps; j++) {
            if (is_prime(concat(p[i], p[j])) and is_prime(concat(p[j], p[i]))) {
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }
    vector<int> v;
    find_clique(v, 5, 0);
    return ans;
}

int32_t main() {
    print_machine_info();
    timer.init();
    cout << "Answer : " << setprecision(10) << fixed << solve() << '\n';
    cout << "Solution executed in " << timer.check() << " ms\n";
}