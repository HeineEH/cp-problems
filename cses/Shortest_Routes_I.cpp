#include <bits/stdc++.h>
 
using namespace std;

#define MAXN (int)1e5
#define ll long long
 
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
bool visited[MAXN];
long long distanceFromStart[MAXN];
vector<pair<ll, ll>> adjList[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
 
        a--; b--;
 
        adjList[a].push_back({w, b});
    }
 

    long long distanceFromStart[n];
    for (int i=0; i<n; i++) distanceFromStart[i] = LLONG_MAX;

    distanceFromStart[0] = 0;
    pq.push({0, 0});
 
    
 
 
    ll currWeight;
    int currNode;
 
    while (!pq.empty()) {
        tie(currWeight, currNode) = pq.top(); pq.pop();        
        
        if (visited[currNode]) {
            continue;
        }
 
        for (auto &adj : adjList[currNode]) {
            ll newWeight = currWeight+adj.first;
            if (newWeight < distanceFromStart[adj.second]) {
                distanceFromStart[adj.second] = newWeight;
                pq.push({newWeight, adj.second});
            }
        }
        visited[currNode] = true;
    }
 
 
    for (auto &a : distanceFromStart) {
        cout << a << ' ';
    }
}