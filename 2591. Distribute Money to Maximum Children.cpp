#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (children > money)
            return -1;
        if (money < 8)
            return 0;
        int ans = money / 8;
        int mod = money % 8;
        int left = children - ans;
        if (ans == children && money % 8 == 0)
            return children;
        if (ans >= children)
            return children - 1;
        if (money % 8 == 4 && (children - ans) == 1)
            return children - 2;
        if (money % 8 >= (children - ans))
            return ans;
        while (mod < left)
        {
            mod += 8;
            left++;
            ans--;
        }
        return ans;
    }
};