#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;

    int count[26]{};

    for (auto &a : s) {
        count[a-'A'] += 1;
    }

    vector<char> half{};


    char middle = 0;

    for (int i=0; i<26; i++) {
        if (count[i] % 2 != 0) {
            if (middle != 0) {
                cout << "NO SOLUTION";
                return 0;
            }
            middle = i+'A';
        }

        for (int j=0; j<count[i]/2; j++) half.push_back(i + 'A');
    }

    for (int i=0; i<half.size(); i++) {
        cout << half[i];
    }

    if (middle) {
        cout << middle;
    }

    for (int i=half.size()-1; i>=0; i--) {
        cout << half[i];
    }

}