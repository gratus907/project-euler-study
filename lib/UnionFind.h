#ifndef PROJECT_EULER_STUDY_UNIONFIND_H
#define PROJECT_EULER_STUDY_UNIONFIND_H

#include "PEBasic.h"

struct DSU
{
    vector<int> par, sz;

    DSU() { init(0); }

    void init(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i, sz[i] = 1;
        }
    }

    int find(int x) { return x == par[x] ? x : (par[x] = find(par[x])); }

    int get_size(int k) { return sz[find(k)]; }

    void unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        sz[u] = 0;
        par[u] = par[v];
    }
};

#endif //PROJECT_EULER_STUDY_UNIONFIND_H
