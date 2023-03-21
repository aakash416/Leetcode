#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int x = 0;
        int n = nums.size();
        long long count = 0, len = 0;
        vector<int> binarynums(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= x && nums[i] == 0)
                binarynums[i] = 1;
            else
                binarynums[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (binarynums[i] == 1)
            {
                int j;

                for (j = i + 1; j < n; j++)
                    if (binarynums[j] != 1)
                        break;
                len = j - i;
                count += (len) * (len + 1) / 2;
                i = j;
            }
        }

        return count;
    }
};
/*
Time Complexity: O(n), where n is the number of elements in the array.
Auxiliary Space: O(n).
Another Method: We can improve the above solution without using extra space keeping the time complexity O(n). Instead of marking elements as 0 and 1 we can keep track of start and end of each such region and update the count whenever the region ends.  */