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
        unordered_set<int> s(nums.begin(), nums.end());
        
        // remove nodes from start if they are in nums
        while (head && s.count(head->val)) {
            head = head->next;
        }

        // now traverse and remove internal nodes
        ListNode* temp = head;
        while (temp && temp->next) {
            if (s.count(temp->next->val)) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};
