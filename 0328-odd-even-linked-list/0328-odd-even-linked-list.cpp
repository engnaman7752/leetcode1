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
        if(head==nullptr)return nullptr;
        ListNode* even=new ListNode(0);
        ListNode* dummy=even;
        ListNode* ans=head;
        ListNode* pre=NULL;
        while(head ){
            even->next=head->next;
            even=even->next;
            if(head->next)
            head->next=head->next->next;
            pre=head;
            head=head->next;
        }
        pre->next=dummy->next;
        return ans;
    }
};