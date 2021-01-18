
// Created by ahmeddrawy on 1/18/21.
// adding two linked lists as numbers with digits and remainder
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ret = NULL;
        ListNode * prev= NULL;
        int rem = 0 ;
        while(true){
            if(l1 == NULL && l2 == NULL && rem == 0)
                break;
            int s = 0 ;
            if(l1){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2){
                s+=l2->val;
                l2 = l2->next;
            }
            s+=rem;

            if(prev == NULL){
                ret = new ListNode(s%10);
                rem = s/10;
                prev = ret;
            }
            else{
                prev->next = new ListNode(s%10);
                rem = s/10;
                prev = prev->next;
            }
        }
        return ret;
    }
};

