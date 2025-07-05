/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* copyRandomList(Node* head) {
        Node * it = head;

        unordered_map<Node*,Node*>mp;


        while(it){
            Node * newNode = new Node(it->val);
            mp[it] = newNode;
            it=it->next;
        }    
        it = head;

        while(it){
            Node * copyNode = mp[it];
            copyNode->next = mp[it->next];
            copyNode->random = mp[it->random];
            it=it->next;
        }    
        return mp[head];
    }
};
