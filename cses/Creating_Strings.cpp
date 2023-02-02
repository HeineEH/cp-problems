#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> a{};

    // a.insert(s);
    do {
        a.insert(s);
    } while ( std::next_permutation(s.begin(), s.end()) );
    

    cout << a.size() << '\n';

    for (auto i : a) {
        cout << i << '\n';
    }

}