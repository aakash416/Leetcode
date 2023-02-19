#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(int n)
    {
        if (n == 0)
            return 0;
        int x = floor(log2(n)), y = ceil(log2(n));
        if (abs(pow(2, y) - n) < abs(pow(2, x) - n))
        {
            return 1 + minOperations(abs(pow(2, y) - n));
        }
        else
        {
            return 1 + minOperations(abs(pow(2, x) - n));
        }
    }
};
