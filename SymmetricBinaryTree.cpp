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
    bool solve(TreeNode * root1,TreeNode * root2){
        if(!root1 || !root2){
            return root1==root2;
        }
        if(root1->val != root2->val)return 0;

        return solve(root1->left,root2->right)&&solve(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return solve(root->left,root->right);
    }
};
