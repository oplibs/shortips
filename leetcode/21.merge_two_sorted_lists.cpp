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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }else if(list2==nullptr){
            return list1;
        }
        ListNode* presult=new ListNode(0, nullptr);
        ListNode* temp=presult;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
                temp->next=nullptr;
            }else{
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
                temp->next=nullptr;
            }
        }
        temp->next=(list1==nullptr)?list2:list1;
        ListNode* ret = presult->next;
        delete presult;
        return ret;
    }
};