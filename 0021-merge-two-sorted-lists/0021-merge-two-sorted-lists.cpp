/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1 || !list2) // if any of the list is empty
            return list1 ? list1 : list2; // return the other list
        ListNode* head = nullptr;
        if (list1->val <= list2->val) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }
        return head;
    }
};