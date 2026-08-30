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
    ListNode* rotate(ListNode* head){
        ListNode* temp = head;
        if(temp->next==NULL) return head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        ListNode* front = temp->next;
        temp->next = NULL;
        front->next = head;
        return front;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        k = k%n;
        ListNode* main = head;
        for(int i = 0;i<k;i++){
            main = rotate(main);
        }
        return main;
    }
};