#include "bits/stdc++.h"
#define DIM 100007

using namespace std;

typedef long long ll;

ll n, m, v1, v2, v, ts, vis[DIM], c;

bool fl, x;

vector <ll> a[DIM];

pair <ll, ll> f[DIM];

void dfs(ll v, ll p) {
    ts ++;
    vis[v] = 1;

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (vis[to] == 0) dfs(to, v);
        else if (to != p && f[to].first == 0) fl = false; //якщо повернулись в "сіру" вершину -> знайшли цикл
    }

    ts ++;
    f[v] = make_pair(ts, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i =1 ;i <= m; i ++) {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
    }

    fl = true;
    for (int i = 1; i <= n; i ++) {
        if (vis[i] == 0) {
            dfs(i, -1);
        }
    }

    if (!fl) {
        cout << -1 << endl;
        return 0;
    }

    sort(f + 1, f + 1 + n);
    reverse(f + 1, f + 1 + n);

    for (int i = 1; i <= n; i ++) {
        cout << f[i].second << ' ';
    }
    return 0;
}