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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* pre=NULL;
        if(head->next==nullptr)return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* del=pre->next;
        pre->next=pre->next->next;
        delete del;
        return head;

    }
};