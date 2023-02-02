#include <bits/stdc++.h>

using namespace std;

int N = 8;
bool R[8][8]{};
long long ans = 0;

bool colArr[8]{false};
bool diag1Arr[15]{false};
bool diag2Arr[15]{false};


void solve(int queensPlaced) {
    if (queensPlaced == N) {
        ans ++;
        return;
    }

    for (int x=0; x<N; x++) {
        int diag1 = x+queensPlaced;
        int diag2 = x-queensPlaced+7;

        if (colArr[x] || diag1Arr[diag1] || diag2Arr[diag2] || R[queensPlaced][x]) continue;

        colArr[x] = true; 
        diag1Arr[diag1] = true; 
        diag2Arr[diag2] = true;

        solve(queensPlaced+1);

        colArr[x] = false; 
        diag1Arr[diag1] = false; 
        diag2Arr[diag2] = false; 
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for (auto &a : R) {
        for (auto &b : a) {
            char c;
            cin >> c;
            b = c == '*';
        }
    }

    solve(0);

    cout << ans;
}