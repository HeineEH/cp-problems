#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    unsigned long long int count = 0;
    unsigned int prev_val = 0;

    for (int i=0; i<n; i++) {
        unsigned int val;
        cin >> val;

        if (val < prev_val) {
            count += prev_val-val;
        } else {
            prev_val = val;
        }


    }

    cout << count;
    
    return 0;
}