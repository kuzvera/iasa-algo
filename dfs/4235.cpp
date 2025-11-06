//головна ідея в тому, що така (-і) вершина (-и) будуть знаходитись на діаметрі
//для відновлення шляху (діаметру) зберігатимемо par[v] - вершина з якої ми потрапили до вершини v
//і в залежності від парності діаметра виведемо середну (1 або 2 вершини)

#include "bits/stdc++.h"
#define DIM 30007

using namespace std;

typedef long long ll;

ll n, m, p, v, ts, dist[DIM], par[DIM], c, mdist, mv;

bool fl, x;

vector <ll> a[DIM];

pair <ll, ll> f[DIM];

void dfs(ll v) {
    c ++;

    for (int i = 0; i < a[v].size(); i ++) {
        int to = a[v][i];
        if (dist[to] == 0) {
            dist[to] = dist[v] + 1;
            par[to] = v;
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
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i ++) {
        cin >> p;
        a[i].push_back(p);
        a[p].push_back(i);
    }

    dist[1] = 1;
    mv = 0; mdist = 0;
    dfs(1);

    for (int i = 1; i <= n; i ++){ dist[i] = 0; par[i] = 0;}
    dist[mv] = 1;
    mdist = 1;
    dfs(mv);

    ll ver = mv;

    while (dist[ver] > mdist / 2 + 1) ver = par[ver];
    if (mdist % 2 == 0) {
        cout << ver << ' ' << par[ver] << endl;
    }
    else {
        cout << ver << endl;
    }
    return 0;
}