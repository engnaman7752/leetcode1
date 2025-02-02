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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return NULL;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* a=lists[i];
            while(a)
            {
                pq.push(a->val);
                a=a->next;
            }
        }
        if (pq.empty()) return nullptr;
        ListNode* ans=new ListNode(pq.top());
        pq.pop();
        ListNode* temp=ans;
        while(!pq.empty())
        {
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return ans;
    }
};