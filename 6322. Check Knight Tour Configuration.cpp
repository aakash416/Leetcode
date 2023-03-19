#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        int k = 0;
        int left[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int right[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int n = grid.size(), m = grid[0].size();
        while (!q.empty())
        {
            int f = 0;
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                if (x + left[i] >= 0 && x + left[i] < n && y + right[i] >= 0 && y + right[i] < m && grid[x + left[i]][y + right[i]] == k + 1)
                {
                    x = x + left[i], y = y + right[i];
                    f = 1;
                    break;
                }
            }
            if (f)
                q.push({x, y});
            k++;
        }
        if (k == n * m)
            return true;

        return false;
    }
};