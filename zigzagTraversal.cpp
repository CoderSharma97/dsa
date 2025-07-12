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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode *>q;
        q.push(root);

        int direction =0;
        while(!q.empty()){

            int size = q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                if(!direction){
                    temp[i]=node->val;
                }
                else{
                    temp[size-i-1]= node->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
                direction=!direction;
            ans.push_back(temp);

        }
            return ans;
    }
};
