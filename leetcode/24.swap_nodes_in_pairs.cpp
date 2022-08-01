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
    ListNode* swapPairs(ListNode* head) {
      if(head==nullptr || head->next==nullptr){
        return head;
      }
      ListNode* ret = head->next;
      ListNode* cur = head;
      ListNode* prev = nullptr;
      // Draw draw draw
      while (cur!=nullptr && cur->next!=nullptr){
        ListNode* temp;
        if(prev!=nullptr){
          prev->next = cur->next;
        }
        temp = cur->next->next;
        cur->next->next = cur;
        cur->next = temp;
        prev = cur;
        cur = cur->next;
      }
      return ret;
    }
};
