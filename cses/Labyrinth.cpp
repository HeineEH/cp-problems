#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)

typedef pair<int, int> pii;
typedef tuple<int, int, int, pii> tiiipii;

pii directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char dirToChar(pii dir) {
    if (dir == (pii){-1, 0}) return 'L';
    if (dir == (pii){1, 0}) return 'R';
    if (dir == (pii){0, -1}) return 'U';
    if (dir == (pii){0, 1}) return 'D';
}


int main() {
    int n, m;
    cin >> n >> m;

    bool isFloor[m][n]{};
    
    pii startPos;
    pii endPos;

    rep(i, 0, n) {
        rep(j, 0, m) {
            char type; cin >> type;

            switch (type) {
                case '#': continue;
                case '.': isFloor[j][i] = true; break;
                case 'A': startPos = {j, i}; break;
                case 'B': endPos = {j, i}; isFloor[j][i] = true; break;
            }
        }
    }

    bool visited[m][n]{};
    pii prevDir[m][n]{};

    queue<pii> q;
    q.push(startPos);
    bool finished = false;

    while (!q.empty()) {
        int nodeX, nodeY;
        tie(nodeX, nodeY) = q.front(); q.pop();

        if (nodeX == endPos.first && nodeY == endPos.second) {
            finished = true;
            break;
        };

        for (auto dir : directions) {
            int dirX = nodeX+dir.first;
            int dirY = nodeY+dir.second;

            if (dirX < 0 || dirX >= m || dirY < 0 || dirY >= n) continue;
            if (!isFloor[dirX][dirY]) continue;
            if (visited[dirX][dirY]) continue;
            visited[dirX][dirY] = true;

            prevDir[dirX][dirY] = dir;
            q.push({dirX, dirY});
        }
    }

    if (!finished) {
        cout << "NO\n"; 
        return 0;
    }


    int x = endPos.first;
    int y = endPos.second;

    string result{};

    while (true) {
        if (x == startPos.first && y == startPos.second) break;
        pii dir = prevDir[x][y];
        x -= dir.first;
        y -= dir.second;

        result.push_back(dirToChar(dir));
    }

    reverse(result.begin(), result.end());

    cout << "YES" << '\n';
    cout << result.size() << '\n';
    cout << result << '\n';
}