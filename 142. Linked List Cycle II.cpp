#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || head->next == NULL)
            return NULL; // because list needs at least 3 nodes to have a cycle
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            { // means we got the cycle
                while (slow != head)
                { // using this loop we will be finding starting point of loop
                    slow = slow->next;
                    head = head->next;
                }
                return head; // no cycle
            }
        }
        return NULL;
    }
};