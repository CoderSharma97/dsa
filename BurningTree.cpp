/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
     void parentMap(Node * root,unordered_map<Node * ,Node *>&parent,int k,
     Node * &target){
        if(!root)return;
        
        if(root->data == k){
            target = root;
        }

        if(root->left)parent[root->left]=root;
        if(root->right)parent[root->right]=root;


        parentMap(root->left,parent,k,target);
        parentMap(root->right,parent,k,target);
    }
    int minTime(Node* root, int k) {
        // code here
        
         unordered_map<Node * ,Node*>parent;
         Node * target;

        parentMap(root,parent,k,target);
        int ans = 0;

        queue<pair<Node*,int>>q;
        q.push({target,0});
        unordered_map<Node *,bool>visited;
        visited[target]=1;

        while(!q.empty()){
            Node * node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            ans = max(dist,ans);

            if(node->left && !visited[node->left]){
                q.push({node->left,dist+1});
                visited[node->left]=1;
            }
            if(node->right && !visited[node->right]){
                q.push({node->right,dist+1});
                visited[node->right]=1;
            }
            if(parent[node] && !visited[parent[node]]){
                q.push({parent[node],dist+1});
                visited[parent[node]]=1;
            }
        }
        return ans;
        
    }
};
