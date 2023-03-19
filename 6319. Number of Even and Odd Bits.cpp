#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        int bubu = 0;
        int dudu = 0;
        vector<int> vec(2, 0);
        int i = 0;
        while (n)
        {
            if (n & 1)
            {
                if (i % 2 == 0)
                    bubu++;
                else
                    dudu++;
            }
            n >>= 1;
            i++;
        }
        return {bubu, dudu};
    }
};
