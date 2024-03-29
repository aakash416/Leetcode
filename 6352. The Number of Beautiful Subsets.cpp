#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> &nums, int idx, int k, unordered_map<int, int> &mp, int &ans)
    {
        if (idx == nums.size())
            ans++;
        else
        {
            if (!mp[nums[idx] - k] && !mp[nums[idx] + k])
            {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, k, mp, ans);
                mp[nums[idx]]--;
            }
            dfs(nums, idx + 1, k, mp, ans);
        }
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        dfs(nums, 0, k, mp, ans);
        return ans - 1;
    }
};