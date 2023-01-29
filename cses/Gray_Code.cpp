#include <bits/stdc++.h>
using namespace std;

#define rev(i,a,b) for (int i=a; i>b; --i)

vector<int> bitsToFlip(int n) {
    if (n == 0) return {0};

    vector<int> bits = bitsToFlip(n-1);

    vector<int> res = bits;
    res.push_back(n);
    rev(i, bits.size(), 0) res.push_back(bits[i-1]);
    
    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<bool> bits(n, false);

    rev(i, n, 0) cout << bits[i-1]; 
    cout << '\n';

    for (auto &b : bitsToFlip(n-1)) {
        bits[b] = !bits[b];
        rev(i, n, 0) cout << bits[i-1]; 
        cout << '\n';
    }
}