/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head)
            return NULL;
        unordered_map<Node*, Node*> m; // to store the address of the new node and the old node, m[old] = new
        Node* newHead = new Node(head->val);
        m[head] = newHead; // m[old head] = new head
        Node *next = head->next, *prev = newHead;
        while (next) {
            Node* newNode = new Node(next->val);
            m[next] = newNode; // m[old] = new
            prev->next = newNode;
            prev = newNode;
            next = next->next;
        }
        next = head; // reset next to head to traverse again to set the random pointer
        while (next) {
            if (next->random) // if random is not null
                m[next]->random = m[next->random]; // set the random of new node to the new node of the random of the old node
            next = next->next;
        }
        return newHead;
    }
};