//
// Created by ahmeddrawy on 1/5/2021.
//  removing duplicates from linked list
/// using dummy node and 3 pointers to prev,curr,nxt
/// assuming that prev is the last available noede
/// the curr is node we are checking if we have similar in the next ones

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(0,head);
        ListNode * ret = dummy;
        ListNode * prev = dummy;
        ListNode * curr = prev->next;
        if(curr == NULL)
            return ret->next;
        ListNode * nxt = curr->next;
        while(prev->next->next){
            bool yes = 0 ;
            while(nxt &&curr->val ==nxt->val){
                nxt = nxt->next;
                yes = 1;
            }
            if(yes){

                prev->next = nxt;
                curr = nxt;

            }
            else {
                prev = curr ;
                curr = prev->next;

            }
            if(curr ==NULL||curr->next == NULL)
                break;
            nxt = curr->next;
        }
        return ret->next;
    }
};
