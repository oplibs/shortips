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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pFake = new ListNode();
        pFake->next = head;
        ListNode *cur=pFake;
        ListNode *tail=pFake;
        size_t pos = 0;
        while(pos<n){
            tail = tail->next;
            pos++;
        }
        while(tail->next!=nullptr){
            cur=cur->next;
            tail = tail->next;
        }
        cur->next=cur->next->next;
        ListNode* ret = pFake->next;
        delete pFake;
        return ret;
    }
};
