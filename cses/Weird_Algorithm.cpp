#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> hist{n};

    while (n != 1) {
        if (n & 1) {
            n = n*3 + 1;
        } else {
            n /= 2;
        }
        hist.push_back(n);
    }

    for (auto el : hist) {
        cout << el << " ";
    }
    
    return 0;
}