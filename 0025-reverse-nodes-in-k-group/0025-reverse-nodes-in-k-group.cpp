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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* newhead=reverse(head->next);
        ListNode* forw=head->next;
        forw->next=head;
        head->next=nullptr;
        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr)return head;
        int cnt=k-1;
        ListNode* temp=head;
        while(cnt--){
            temp=temp->next;
            if(temp==nullptr)return head;
        }
        ListNode* next=reverseKGroup(temp->next,k);
        temp->next=nullptr;
        ListNode* ans=reverse(head);
        head->next=next;
        return ans;


    }
};