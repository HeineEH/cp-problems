#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    int res = 1;
    for (int i=0; i<n; i++) res = (res*2) % (1000000000+7);
    cout << res;
}