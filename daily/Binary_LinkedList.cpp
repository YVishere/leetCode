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
 #include <cmath>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *curr = head;
        double result = 0;
        while(curr){
            result = curr->val + (result*2);
            curr = curr->next;
        }
        return result;
    }
};