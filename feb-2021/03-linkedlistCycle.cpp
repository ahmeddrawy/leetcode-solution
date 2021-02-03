//
// Created by ahmeddrawy on 2/3/21.
//
/**
 *  two solutions
 *  time for both O(n)
 *  memory for first is O(n)
 *  second memory is O(1)
 *      using Floyd's fast and slow pointers to detect loops
 */
class Solution {
    unordered_map<ListNode*,bool> visited;
public:
    bool hasCycle(ListNode *head) {
        return solve(head);
    }
    bool solve(ListNode *head){
        ListNode * slow = head, * fast = head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }

    bool solve2(ListNode *head){
        if(head == NULL)
            return false;
        if(visited[head])
            return true;
        visited[head] = true;
        return solve(head->next);
    }
};