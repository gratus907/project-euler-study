#include "../lib/PEBasic.h"
#include "../lib/Primes.h"
#include "../lib/UnionFind.h"
#include <unistd.h>
#include <pthread.h>
struct thread_arg {
    int lo, hi, thr, with;
};

vector<int> p;
bool conn(int a, int b) {
    if (a < b) return conn(b, a);
    int cnt = 0;
    while (a) {
        if (a % 10 != b % 10 || b == 0) cnt++;
        if (cnt > 1) return false;
        a /= 10; b /= 10;
    }
    return cnt <= 1;
}
int nthread = 8;

vector<int> ptask[64];
vector<int> check_range(int lo, int hi, int with) {
    vector<int> v;
    for (int i = lo; i < hi; i++) {
        if (conn(p[i], p[with])) {
            v.push_back(i);
        }
    }
    return v;
}
void* task (void *_tharg) {
    thread_arg *tharg = (thread_arg *)_tharg;
    ptask[tharg->thr] = check_range(tharg->lo, tharg->hi, tharg->with);
    pthread_exit(NULL);
}
int64_t solve() {
    int64_t ans = 0;
    p = primes(10000000);
    int ps = p.size();
    DSU D; D.init(707070);
    pthread_t threads[64];
    for (int i = 1; i < ps; i++) {
        if (i > 8192) {
            nthread = min(i / 4096, 16);
            for (int t = 0; t < nthread; t++) {
                int lo = t * (i / nthread);
                int hi = (t + 1) * (i / nthread);
                if (t + 1 == nthread) hi = i;
                thread_arg* tharg = (thread_arg *) malloc(sizeof(thread_arg));
                tharg->lo = lo; tharg->hi = hi; tharg->with = i; tharg->thr = t;
                pthread_create(&threads[t], NULL, task, tharg);
            }
            for (int t = 0; t < nthread; t++) {
                pthread_join(threads[t], NULL);
            }
            for (int t = 0; t < nthread; t++) {
                for (int j : ptask[t]) {
                    D.unite(i, j);
                }
            }
        }
        else {
            for (int j = 0; j < i; j++) {
                if (conn(p[i], p[j])) {
                    D.unite(i, j);
                }
            }
        }

        if (D.find(0) != D.find(i)) {
            ans += (int64_t)p[i];
        }
    }
    return ans;
}
int32_t main() {
    print_machine_info();
    timer.init();
    cout << "Answer : " << solve() << '\n';
    cout << "Solution executed in " << timer.check() << " ms\n";
}