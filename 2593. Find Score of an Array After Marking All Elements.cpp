#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        long long ans = 0;
        set<pair<int, int>> st;
        for (int i = 0; i < nums.size(); ++i)
        {
            st.insert({nums[i], i});
        }
        for (auto s : st)
        {
            if (nums[s.second])
            {
                nums[s.second] = 0;
                if (s.second - 1 >= 0)
                    nums[s.second - 1] = 0;
                if (s.second + 1 < nums.size())
                    nums[s.second + 1] = 0;
                ans += s.first;
            }
        }
        return ans;
    }
};