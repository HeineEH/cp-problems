#include <bits/stdc++.h>

using namespace std;

void tower(int n, int from, int to, int extra) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }


    tower(n-1, from, extra, to);

    cout << from << ' ' << to << '\n';
    
    tower(n-1, extra, to, from);



    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;

    int p = pow(2, n)-1;
    

    cout << p << '\n';
    tower(n, 1, 3, 2);
}