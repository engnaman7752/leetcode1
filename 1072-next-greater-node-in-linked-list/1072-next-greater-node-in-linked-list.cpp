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
    ListNode* reverse1(ListNode* head)
    { ListNode* current=new ListNode();
    ListNode* pre=new ListNode();
    ListNode* forward=new ListNode();

current=head;
pre=NULL;
while(current)
{
    forward=current->next;
    current->next=pre;
    pre=current;
    current=forward;

}
return pre;}
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>st;
        vector<int>ans;
        head=reverse1(head);
        while(head)
        {
            while((!st.empty())&&((head->val)>=st.top()))
            st.pop();
            if(st.empty())
            ans.push_back(0);
            else
            ans.push_back(st.top());
            st.push(head->val);
            head=head->next;


        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};