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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* tail = head;
        ListNode* curr = tail->next;

        while(curr!=NULL){
            if(tail->val<=curr->val){
                tail = tail->next;
            }else{
                tail->next = curr->next;
                ListNode* prev = dummy;
                while(prev->next->val<=curr->val){
                    prev = prev->next;
                }        
                curr->next = prev->next;
                prev->next = curr;
                
            }
            curr = tail->next;
        }  
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};