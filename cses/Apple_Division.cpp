#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)

#define ll long long

#define MAXN 21
ll apples[MAXN];

vector<ll> allCombs(int idx) {

    if (idx == 0) return {apples[0], -apples[0]};

    vector<ll> combinations = allCombs(idx-1);
    vector<ll> res;

    for (auto a : combinations) {
        res.push_back(a-apples[idx]);
        res.push_back(a+apples[idx]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    rep(i, 0, n) cin >> apples[i];

    vector<ll> combs = allCombs(n-1);
    for (auto &comb : combs) comb = abs(comb);
    ll minComb = *min_element(combs.begin(), combs.end());
    cout << minComb;
}