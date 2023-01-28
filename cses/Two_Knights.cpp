#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        ll x = pow(i, 2ll);
        ll all_possibilities = (x*(x-1))/2;
        ll all_invalid_combinations = 2*2*(i-1)*(i-2);
        cout << all_possibilities-all_invalid_combinations << '\n';
    }
}