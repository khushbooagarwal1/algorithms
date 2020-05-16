/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/ */


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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* even = head->next;
        ListNode* evenHead = even;
        ListNode* oddHead = head;
        while(even != NULL && even->next != NULL){
            head->next = even->next;
            head = head->next;
            even->next = head->next;
            even = even->next;
        }
        head->next = evenHead;
        return oddHead;
    }
};
