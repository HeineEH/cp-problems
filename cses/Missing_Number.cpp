#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    bitset<200000> exists{};

    // int exists = 1 << (n-1);

    for (int i=0; i<n-1; i++) {
        int num;
        cin >> num;

        exists[num-1] = 1;

    }
    
    
    for (int i=0; i<n; i++) {
        if (exists[i] == 0) {
            cout << (i+1);
            break;
        }
    }
    
    return 0;
}