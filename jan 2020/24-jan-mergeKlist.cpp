//
// Created by ahmeddrawy on 1/24/21.
//
/** merge using double pointers or index in vector
 * we iterate over all elements get min, then make new node from min and move next and move
 *
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * root = new ListNode();
        if(lists.size() == 0 )
            return root->next;
        ListNode * prev =root;

        while(true){
            int indx = -1;
//            for(int i = 0 ; i < lists.size() ;++i){
//                if(lists[i] && lists[i]->val < mn){
//                    mn = lists[i]->val;
//                    indx = i;
//                }
//            }
//            if(indx == -1 )
//                break;
            int mn = 1e5;
            ListNode **curr = NULL;
//

            for(ListNode *& it : lists){
                if( it && it->val < mn ){
                    curr = &it;
                    mn = it->val;
                }
            }
            if(curr == NULL)
                break;
            ///we need to move curr to curr->next
            prev->next = new ListNode(mn);
            *curr = (*curr)->next;
//            lists[indx] = lists[indx]->next;
            prev = prev->next;
        }
        return root->next;
    }
};