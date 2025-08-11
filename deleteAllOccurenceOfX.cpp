// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node * head = *head_ref;
        
        Node * it = head;
        
        while(it){
            if(it->data==x){
                if(it==*head_ref){
                    (*head_ref)=(*head_ref)->next;
                    if(*head_ref)(*head_ref)->prev = NULL;
                }
                else{
                    it->prev->next = it->next;
                    if(it->next)it->next->prev=it->prev;
                }
            }
            it=it->next;
        }
        
    }
};
