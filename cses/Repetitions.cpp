#include <bits/stdc++.h>

using namespace std;

int main() {

    string seq;

    cin >> seq;

    int longest_seq = 0;
    int curr_seq = 0;
    char prev_char{};

    for (int i=0; i<seq.size(); i++) {
        if (seq[i] != prev_char) {
            curr_seq = 0;
            prev_char = seq[i];
        }
        curr_seq += 1;
        if (curr_seq > longest_seq) {
            longest_seq = curr_seq;
        }
    }

    cout << longest_seq;
    
    
    return 0;
}