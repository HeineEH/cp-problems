#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    int zeroCount = 0;
    for (int i=5; i<=n; i*=5) {
        zeroCount += n/i;
    }
    
    cout << zeroCount;
}