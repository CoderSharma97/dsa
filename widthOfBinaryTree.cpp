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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode * ,int>>q;
        q.push({root,0});
        long long ans = 0;

        while(!q.empty()){
            

            int size = q.size();
            long long start = 0;
            long long end = 0;
            long long mini = q.front().second;
            for(int i=0;i<size;i++){
                TreeNode * node = q.front().first;
                long long pos = q.front().second-mini;
                q.pop();
                if(i==0){
                    start = pos;
                }
                if(i==size-1)end = pos;
                if(node->left){
                    q.push({node->left,2*pos+1});
                }
                if(node->right){
                    q.push({node->right,2*pos+2});
                }
            }
            if(ans <end-start+1){
                ans = end-start+1;
            }
        }
        return ans;
    }
};
