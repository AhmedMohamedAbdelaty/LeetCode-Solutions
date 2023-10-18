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
        ListNode* head = new ListNode();
        ListNode *cursor_1 = list1, *cursor_2 = list2, *new_list = head;
        int f=0;
        while (cursor_1 != nullptr && cursor_2 != nullptr){
            if (cursor_1->val < cursor_2->val){
                new_list->next = cursor_1;
                cursor_1 = cursor_1->next;
            }
            else{
                new_list->next = cursor_2;
                cursor_2 = cursor_2->next;
            }
            new_list = new_list->next;
        }
        while (cursor_1 != nullptr){
            new_list->next = cursor_1;
            cursor_1 = cursor_1->next;
            new_list = new_list->next;
        }
        while (cursor_2 != nullptr){
            new_list->next = cursor_2;
            cursor_2 = cursor_2->next;
            new_list = new_list->next;
        }
        return head->next;
    }
};