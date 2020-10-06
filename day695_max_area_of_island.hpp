#include "common.h"

static vector<vector<int>> dirs{ { 0,-1 },{ -1,0 },{ 0,1 },{ 1,0 } };
void helper(vector<vector<int>>& grid, int i, int j, int& cnt, int& res) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
    res = max(res, ++cnt);
    grid[i][j] *= -1;
    for (auto dir : dirs) {
        helper(grid, i + dir[0], j + dir[1], cnt, res);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 1) continue;
            int cnt = 0;
            helper(grid, i, j, cnt, res);
        }
    }
    return res;
}

int maxAreaOfIsland_2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 1) continue;
            int cnt = 0;
            queue<pair<int, int>> q{ { { i, j } } };
            grid[i][j] *= -1;
            while (!q.empty()) {
                auto t = q.front(); q.pop();
                res = max(res, ++cnt);
                for (auto dir : dirs) {
                    int x = t.first + dir[0], y = t.second + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] <= 0) continue;
                    grid[x][y] *= -1;
                    q.push({ x, y });
                }
            }
        }
    }
    return res;
}

void test_day695()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(grid);
}