/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto [ls,lc] = dfs(root->left);
        auto [rs,rc] = dfs(root->right);
        int sum = ls + rs + root->val;
        int n = lc + rc + 1;
        if(sum/n==root->val) ans++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};