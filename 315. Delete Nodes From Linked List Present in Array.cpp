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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set for fast lookups
        unordered_set<int> toDelete(nums.begin(), nums.end());
        
        // Create a dummy node that will be the new head of the modified list
        ListNode dummy;
        dummy.next = head;
        ListNode* current = &dummy;
        
        // Traverse the linked list
        while (current->next != nullptr) {
            if (toDelete.find(current->next->val) != toDelete.end()) {
                // Skip the node to be deleted
                current->next = current->next->next;
            } else {
                // Otherwise, move to the next node
                current = current->next;
            }
        }
        
        // Return the modified list starting from dummy's next node
        return dummy.next;
    }
};
