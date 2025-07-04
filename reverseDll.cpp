/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode * q = head;
        DLLNode * r  = NULL;
        
        while(q){
            
            DLLNode * p = q->next;
            
            q->prev  =q->next;
            q->next = r;
            r=q;
            q=p;
        }
        return r;
    }
};
