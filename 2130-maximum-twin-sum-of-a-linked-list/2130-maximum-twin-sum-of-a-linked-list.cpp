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
        if(head==nullptr)return head;
        ListNode* pre=nullptr;
        ListNode* curr=head;
        ListNode* forw=head->next;
        while(curr){
            curr->next=pre;
            pre=curr;
            curr=forw;
            if(forw)
            forw=forw->next;
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        if(head==nullptr)return 0;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=nullptr;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        ListNode* temp=pre->next;
        pre->next=nullptr;
        temp=reverse(temp);
        int ans=INT_MIN;
        while(temp){
        ans=max(ans,temp->val+head->val);
        temp=temp->next;
        head=head->next;
        }
        return ans;
    }
};