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

        ListNode dummy(0);
        ListNode *prev = &dummy;

        dummy.next = head;

        while(true){
            ListNode *tail = prev->next;
            for (int i = 1; i < k && tail; i++){
                tail = tail->next;
            }

            if(!tail){
                break;
            }

            ListNode *curr = prev->next;
            ListNode *next = tail->next;
            ListNode *p = next;

            while(curr != next){
                ListNode *tmp = curr->next;
                curr->next = p;
                p = curr;
                curr = tmp;
            }
            
            ListNode *t = prev->next;
            prev->next = tail;
            prev = t;
        }
        return dummy.next;
    }
};