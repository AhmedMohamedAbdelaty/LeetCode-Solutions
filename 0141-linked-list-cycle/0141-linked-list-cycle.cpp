/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_map<ListNode*, int> m;

public:
    bool hasCycle(ListNode* head)
    {
        ListNode* curr = head;
        while (curr != NULL) {
            if (m.find(curr) != m.end()) {
                return true;
            }
            m[curr] = 1;
            curr = curr->next;
        }
        return false;
    }
};