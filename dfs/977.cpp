#include "bits/stdc++.h"
#define DIM 107

using namespace std;

typedef long long ll;

ll n, m, v1, v2, v, ts, vis[DIM], c;

bool fl, x;

vector <ll> a[DIM];

void dfs(ll v, ll p) {
    vis[v] = 1;
    c ++;
    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (vis[to] == 0) {
            dfs(to, v);
        }
        else if (to != p) fl = false;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> x;
            if (x) {
                a[i].push_back(j);
                m ++;
            }
        }
    }

    m /= 2;
    fl = true;

    if (n != m + 1) fl = false;
    dfs(1, -1);
    if (c != n) fl = false;

    if (fl) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}