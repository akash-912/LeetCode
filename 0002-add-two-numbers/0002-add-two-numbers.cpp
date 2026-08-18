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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* result = new ListNode(-1);
        ListNode* curr = result;
        while(t1||t2){
            int num = carry;
            if(t1) num += t1->val;
            if(t2) num += t2->val;
            
            ListNode* temp = new ListNode(num%10);
            curr->next = temp;
            curr = curr->next;
            carry = num/10;
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }
        return result->next;
        
    }
};