// Problem link - https://leetcode.com/problems/middle-of-the-linked-list/description/
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
    ListNode* middleNode(ListNode* head) {
        
        
        ListNode* first = head;
        ListNode* second = first->next;
        if (first->next == NULL) return head;
        
        while(second != NULL){
            first = first->next;
            second = second->next;
            if (second == NULL) return first;
            second = second->next;
        }
        return first;
    }
};
