#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int w, h;
vector<vector<int>> arr;

void DFS(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || arr[x][y] == 0) return;

    arr[x][y] = 0;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        DFS(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> w >> h; // w가 x h가 y
        if (w == 0 && h == 0) break; 

        arr.assign(h, vector<int>(w));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }

        int result = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] == 1) {  
                    DFS(i, j);  
                    result++;  
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}
