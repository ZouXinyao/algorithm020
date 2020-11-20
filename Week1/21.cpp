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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        while(tmp1 && tmp2) {
            if(tmp1->val < tmp2->val) {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if(tmp1) tmp->next = tmp1;
        else tmp->next = tmp2;
        return head->next;
    }
};