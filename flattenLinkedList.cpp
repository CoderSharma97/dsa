/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node * helper(Node * h1,Node * h2){
        Node * it1 = h1;
        Node * it2 = h2;
        Node * newNode = new Node(-1);
        Node * head = newNode;
        
        while(it1 && it2){
            if(it1->data <it2->data){
                newNode->bottom = it1;
                it1=it1->bottom;
            }
            else{
                newNode->bottom = it2;
                it2=it2->bottom;
            }
            newNode = newNode->bottom;
        }
        
        if(it1){
            newNode->bottom = it1;
            it1=it1->bottom;
        }
        if(it2){
            newNode->bottom = it2;
            it2=it2->bottom;
        }
        return head->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
        Node * ans = NULL;
        
        while(root){
            ans = helper(ans,root);
            root=root->next;
        }
        return ans;
    }
};
