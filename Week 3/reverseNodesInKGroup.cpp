// Problem link - https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        ListNode* currGroupHead = head;
        
        while (true) {
            int count = 0;
            ListNode* temp = currGroupHead;
            // Check if there are at least k nodes left
            while (temp && count < k) {
                temp = temp->next;
                count++;
            }
            if (count < k) break; // Less than k nodes left
            
            // Reverse the current group
            ListNode* prev = prevGroupTail;
            ListNode* curr = currGroupHead;
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // Connect the previous group tail to the reversed group head
            prevGroupTail->next = prev;
            
            // Update pointers for the next iteration
            prevGroupTail = currGroupHead;
            currGroupHead = curr;
        }
        
        // Connect the remaining nodes
        prevGroupTail->next = currGroupHead;
        
        return dummy->next;
    }
};
