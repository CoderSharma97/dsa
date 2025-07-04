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
    ListNode * helper(ListNode * q,ListNode * r){
        if(!q)return r;

        ListNode* p = q->next;
        q->next = r;

        return helper(p,q);
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode * q = head;
        // ListNode * r = NULL;

        // while(q){
        //     ListNode * p = q->next;

        //     q->next= r;
        //     r=q;
        //     q=p;
        // }
        // return r;
        return helper(head,NULL);
    }
};
