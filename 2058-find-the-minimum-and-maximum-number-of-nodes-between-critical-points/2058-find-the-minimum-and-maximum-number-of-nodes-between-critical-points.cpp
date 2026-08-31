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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next) return {-1,-1};
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nn = curr->next;
        int mndis = INT_MAX, mxdis = INT_MIN;
        int n1 = -1, n2 = -1, p = 2; 
        int n = -1;
        while(nn){
            if(prev->val < curr->val && curr->val > nn->val){
                n2 = n1;
                n1 = p;
                if(n == -1) n = p;
                if(n2 != -1){
                    mndis = min(mndis, n1 - n2);
                    mxdis = max(mxdis, n1 - n);
                }
            }
            else if(prev->val > curr->val && curr->val < nn->val){
                n2 = n1;
                n1 = p;
                if(n == -1) n = p;
                if(n2 != -1){
                    mndis = min(mndis, n1 - n2);
                    mxdis = max(mxdis, n1 - n);
                }
            }
            p++;
            prev = curr;
            curr = nn;
            nn = nn->next;
        }
        if(n2 == -1) return {-1, -1};
        return {mndis, mxdis};
    }
};