#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }


    
    bool n_is_even = (n&1) == 0;

    for (int i=1; i<=n; i++) {

        cout << ((i)*2-1)%(n+n_is_even)+1  << " ";
    }

    
    return 0;
}