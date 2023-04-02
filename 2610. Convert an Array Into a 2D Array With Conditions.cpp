#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ans;
        map<int, int> m;
        for (auto &i : nums)
            m[i]++;
        while (!m.empty())
        {
            vector<int> v;
            vector<int> vec;
            for (auto x : m)
            {
                v.push_back(x.first);
                m[x.first]--;
                if (m[x.first] == 0)
                    vec.push_back(x.first);
            }
            ans.push_back(v);
            for (auto &x : vec)
                m.erase(x);
        }
        return ans;
    }
};