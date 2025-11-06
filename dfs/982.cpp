#include "bits/stdc++.h"
#define DIM 107

using namespace std;

typedef long long ll;

ll n, m, v1, v2, v, ts, vis[DIM], c;

bool fl, x;

vector <ll> a[DIM];

pair <ll, ll> f[DIM];

void dfs(ll v) {
    c ++;
    vis[v] = 1;

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (vis[to] == 0) dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i =1 ;i <= m; i ++) {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    dfs(1);

    if (c != n) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}