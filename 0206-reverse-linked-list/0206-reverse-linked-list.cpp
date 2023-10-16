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
    ListNode* reverseList(ListNode* head)
    {
        // if the list is empty
        if (head == nullptr)
            return head;

        // if the list only has one element
        if (head->next == nullptr)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr->next != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr->next = prev; 
        head->next = nullptr;
        return curr;
    }
};