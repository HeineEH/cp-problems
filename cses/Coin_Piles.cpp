#include <bits/stdc++.h>
using namespace std;

void do_task() {
    int a, b;
    cin >> a >> b;
    if (b > a) swap(a,b);

    bool lowestIsEnough = b >= (a/2);
    bool sumIsFactorOfThree = (a+b) % 3 == 0;

    cout << (sumIsFactorOfThree && lowestIsEnough ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int i;
    cin >> i;

    while (i--) {
        do_task();
    }
}