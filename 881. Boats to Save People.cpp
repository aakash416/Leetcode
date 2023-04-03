#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while (i <= j)
        {
            if (people[j] + people[i] <= limit)
            {
                i++;
            }
            j--;
            boats++;
        }
        return boats;
    }
};