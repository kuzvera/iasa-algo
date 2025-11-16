#include "bits/stdc++.h"
#define DIM 107

using namespace std;

typedef long long ll;

ll v1, v2, n, m, k, c, res, vis[DIM], match_left[DIM];

bool if_match_right[DIM];

vector <ll> a[DIM];

bool dfs(ll v) {
    if (vis[v]) return 0;

    vis[v] = 1;
    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (!match_left[to]) {
            match_left[to] = v;
            return 1;
        }
    }

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (dfs(match_left[to])) {
            match_left[to] = v;
            return 1;
        }
    }

    return 0;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++) {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
    }

    while (1) {
        c = 0;
        memset (vis, 0, sizeof(vis)); //очищення масиву

        for (int i = 1; i <= n; i ++) {
            if (if_match_right[i] == 0 && dfs(i)) {
                if_match_right[i] = 1;
                res ++;
                c ++;
            }
        }

        if (c == 0) {
            break;
        }
    }
    cout << res << endl;
    for (int i = 1; i <= m; i ++) {
        if (match_left[i]) {
            cout << match_left[i] << ' ' << i << endl;
        }
    }
    return 0;
}