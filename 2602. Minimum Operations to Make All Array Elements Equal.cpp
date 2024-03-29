#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        vector<long long> prefix(n, 0);

        std::sort(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            prefix[i] = sum;
        }

        int m = queries.size();
        vector<long long> res(m, 0);

        for (int i = 0; i < m; ++i)
        {
            long long q = queries[i];
            long long low = std::lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            if (low == nums.size())
            {
                res[i] = q * n - prefix[n - 1];
                continue;
            }

            long long more = (prefix[n - 1] - prefix[low] + nums[low]) - (n - low) * q;
            long long less = low * q - (prefix[low] - nums[low]);

            res[i] = more + less;
        }

        return res;
    }
};