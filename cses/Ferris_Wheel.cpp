#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, x; cin >> n >> x;
    int weights[n];
    rep(i, 0, n) cin >> weights[i];
    sort(weights, weights+n);

    int left = 0;
    int right = n-1;

    int count = 0;

    while (right>=left) {
        count++;

        int left_weight = weights[left];
        int right_weight = weights[right];

        if (right_weight + left_weight > x) {
            right--;
            continue;
        }

        right--;
        left++;

    }

    cout << count << '\n';
}