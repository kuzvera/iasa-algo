#include "bits/stdc++.h"
#define DIM 200007

using namespace std;

typedef long long ll;

ll n, m, v1, v2, v, ts, dist[DIM], c, mdist, mv;

bool fl, x;

vector <ll> a[DIM];

pair <ll, ll> f[DIM];

void dfs(ll v) {
    c ++;

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (dist[to] == 0) {
            dist[to] = dist[v] + 1;
            if (dist[to] > mdist) {
                mdist = dist[to];
                mv = to;
            }
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i =1 ;i < n; i ++) {
        cin >> v1 >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }

    dist[1] = 1;
    mv = 0; mdist = 0;
    dfs(1);

    for (int i = 1; i <= n; i ++) dist[i] = 0;
    dist[mv] = 1;
    mdist = 1;
    dfs(mv);

    cout << mdist - 1 << endl;
    return 0;
}