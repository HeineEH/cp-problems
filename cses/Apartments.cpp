#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;

    int people[n]{};
    int apartments[m]{};
    rep(i, 0, n) cin >> people[i];
    rep(i, 0, m) cin >> apartments[i];

    sort(people, people+n);
    sort(apartments, apartments+m);

    int apartmentUsedCount = 0;
    int personIdx = 0;
    int apartmentIdx = 0;

    bool apartmentTaken[m]{};

    while (apartmentIdx < m && personIdx < n) {
        int apartment = apartments[apartmentIdx];
        int person = people[personIdx];

        if (apartmentTaken[apartmentIdx] || apartment < person-k) {
            apartmentIdx++;
            continue;
        }
        if (apartment > person+k) {
            personIdx++;
            continue;
        }


        personIdx++;
        apartmentUsedCount++;
        apartmentTaken[apartmentIdx] = true;
    }

    cout << apartmentUsedCount << '\n';
}