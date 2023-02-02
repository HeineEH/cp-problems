#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i<b; ++i)

#define ll long long
const ll INF = LLONG_MAX;
ll distances[500][500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;

    rep(i, 0, n)
        rep(j, 0, n) distances[i][j] = (i == j) ? 0 : INF;

    rep(i, 0, m) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--; b--;

        distances[a][b] = distances[b][a] = min(distances[a][b], c);
    }

    rep(i, 0, n)
        rep(j, 0, n)
            rep(k, 0, n) {
                if (distances[i][j] == INF || distances[i][k] == INF) continue;
                distances[j][k] = distances[k][j] = min(distances[j][k], distances[i][j]+distances[i][k]);
            }

    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        ll distance = distances[a][b];
        if (distance == INF) distance = -1;
        
        cout << distance << '\n';
    }
}