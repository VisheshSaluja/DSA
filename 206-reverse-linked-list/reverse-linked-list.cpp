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
    ListNode* reverseList(ListNode* head) {

        ListNode* p = head;
        ListNode* t = NULL;
        ListNode* l = NULL; 
        
        while(p){
            t = p;
            p = p->next;
            t->next = l;
            l = t;
            head = t;
        }

        return head;

    }
};