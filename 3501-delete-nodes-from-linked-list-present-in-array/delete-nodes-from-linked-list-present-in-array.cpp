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
        unordered_set<int> s(nums.begin(), nums.end()); // push nums into set
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while(curr->next!=NULL){
            if(s.count(curr->next->val)){
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};