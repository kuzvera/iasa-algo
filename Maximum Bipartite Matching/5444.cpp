#include "bits/stdc++.h"
#define DIM 207

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll v1, v2, n, m, k, c, res, vis[DIM];
pll match_left[DIM];

bool if_match_right[DIM];

vector <pll> a[DIM];

bool dfs(ll v) {
    if (vis[v]) return 0;

    vis[v] = 1;
    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i].first;
        int edge = a[v][i].second;
        if (!match_left[to].first) {
            match_left[to] = make_pair(v, edge);
            return 1;
        }
    }

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i].first;
        int edge = a[v][i].second;
        if (dfs(match_left[to].first)) {
            match_left[to] = make_pair(v, edge);
            return 1;
        }
    }

    return 0;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++) {
        cin >> v1 >> v2;
        a[v1].push_back(make_pair(v2, i));
    }

    while (1) {
        c = 0;
        memset (vis, 0, sizeof(vis)); //очищення масиву

        for (int i = 1; i <= n; i ++) {
            if (!if_match_right[i] && dfs(i)) {
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
        if (match_left[i].first) {
            cout << match_left[i].second << ' ';
        }
    }
    return 0;
}