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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(l1 == nullptr){
        return l2;
      }else if(l2 == nullptr) {
        return l1;
      }
      ListNode* p1=l1;
      ListNode* p2=l2;
      ListNode* ret = new ListNode(0);
      ListNode* tmp = ret;
      int carry=0;
      do {
        if(p1!=nullptr){
          tmp->val += p1->val;
          p1=p1->next;
        }
        if(p2!=nullptr){
          tmp->val += p2->val;
          p2=p2->next;
        }
        tmp->val += carry;
        if(tmp->val>=10){
          carry = 1;
          tmp->val = tmp->val % 10;
        }else{
          carry = 0;
        }
        if(!(p1 == nullptr && p2 == nullptr && carry == 0)){
          tmp->next = new ListNode(0);
          tmp=tmp->next;
        }
      }while(p1 != nullptr || p2 != nullptr || carry ==1);
      return ret;
      /*
      while(p2 != nullptr){
        int val = p1->val + p2->val + carry;
        if(val>9){
          carry = 1;
        }else{
          carry = 0;
        }
        p1->val  = val % 10;
        if (p1->next == nullptr) {
          p1->next = p2->next;
          break;
        }
        p1=p1->next;
        p2=p2->next;
      }
      if(p1->next==nullptr && carry==1) {
        p1->next = new ListNode(1);
        carry = 0;
        p1 = p1->next;
      } else {
        while(p1 != nullptr){
          int val = p1->val + carry;
          if(val>9){
            carry = 1;
          }else{
            carry = 0;
          }
          p1->val  = val % 10;
          if(p1->next==nullptr && carry==1) {
            p1->next = new ListNode(1);
            carry = 0;
          }
          p1 = p1->next;
        }
      }
      */
      return l1;
    }
};
