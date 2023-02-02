#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    ll sum = 0;

    for (int i=0; i<n; i++) {
        sum += i+1;
    }

    if (sum%2 != 0) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    unordered_set<ll> a;

    ll required_sum = sum/2;
    ll curr_sum = 0;
    ll i = 0;


    while (true) {
        if (required_sum-curr_sum <= n-i) {
            a.insert(required_sum-curr_sum);
            break;
        }

        ll b = n-i;
        a.insert(b);

        i += 1;
        curr_sum += b;
    }

    cout << a.size() << '\n';
    for (auto i : a) {
        cout << i << ' ';
    }


    cout << '\n' << (n-a.size()) << '\n';
    for (int i=1; i<=n; i++) {
        if (a.find(i) != a.end()) {
            continue;
        }

        cout << i << ' ';
    }
}