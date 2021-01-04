//
// Created by ahmeddrawy on 1/4/2021.
//
/** merging two linked lists without reserving the originals
 * we have 3 solutions
 * 2 iterative and 1 recursive
 * we have utility functions to take input, construct lists and print lists
 * TODO extend the code to reserve the originals
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2) return l1;
        // make first list smaller
        if(l1->val > l2->val) swap(l1,l2);
        ListNode * ret = l1;
        // make root points to first node of l1 which is smaller as we checked above
        while(l1->next){
            ///swap l2 with the next of l1 if it's smaller
            if(l1->next->val > l2->val){
                swap(l1->next , l2);
            }
            else
                l1 = l1->next;
        }
        /// add the rest of l2 to the end of the l1 list
        l1->next = l2 ;
        /// return the pointer that points to the root
        return ret;

    }
};
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(0);
        ListNode * p = res;
        if(l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;
        else
        {
            while(l1&& l2){
                if(l1->val < l2->val){
                    p->next=l1;
                    l1=l1->next;
                }

                else{
                    p->next=l2;
                    l2=l2->next;
                }
                p=p->next;
            }
            if(l1)
                p->next = l1;
            else
                p->next = l2;
        }
        return res->next;
    }
};
class Solution3 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 ==NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next , l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1 , l2->next);
            return l2;
        }
    }
};
ListNode * takeList(int n ){
    ListNode * l1 = new ListNode ;
    ListNode * curr1 = l1;
    for (int i = 0; i <n ; ++i) {
        int x ; cin >> x;
        curr1->val = x;
        if(i != n-1)
            curr1->next = new ListNode;
        curr1 = curr1->next;
    }
    return l1;
}
void printList(ListNode * root){
    ListNode * tmp = root;
    while(tmp){
        cout << tmp->val << " ";
        tmp = tmp->next ;
    }
    cout << endl;
    return ;
}