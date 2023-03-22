#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<int> vis(n + 2, 0);
        queue<vector<int>> q;
        vector<vector<pair<int, int>>> Score(n + 1);
        int ans = INT_MAX;
        for (int i = 0; i < roads.size(); i++)
        {
            Score[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            Score[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        q.push({n, INT_MAX});

        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            ans = min(ans, x[1]);
            vis[x[0]] = 1;
            for (auto y : Score[x[0]])
            {
                if (!vis[y.first])
                    q.push({y.first, y.second});
            }
        }
        return ans;
    }
};