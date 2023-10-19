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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        //         Nth from the end, n=1 -> index is length-1 (0-based)
        //         n=2 -> index is length-2 (0-based)
        //         and so on
        int len = get_len(head);
        if (len-n==0) {
            // delete head
            ListNode* temp = head;
            head = head->next;
            delete (temp);
            return head;
        }
        ListNode* to_delete = get_Nth_node(head, len - n);
        ListNode* prev = get_Nth_node(head, len - n - 1);
        prev->next = to_delete->next;
        delete (to_delete);
        return head;
    }
    ListNode* get_Nth_node(ListNode* head, int index)
    {
        ListNode* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr;
    }
    int get_len(ListNode* head)
    {
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};