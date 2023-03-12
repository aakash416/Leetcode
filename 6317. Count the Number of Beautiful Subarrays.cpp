#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        long long n = nums.size(), ans = 0, sum = 0;
        unordered_map<int, int> m;
        m[sum]++;
        for (int i = 0; i < n; i++)
        {
            sum ^= nums[i];
            ans += m[sum];
            m[sum]++;
        }
        return ans;
    }
};