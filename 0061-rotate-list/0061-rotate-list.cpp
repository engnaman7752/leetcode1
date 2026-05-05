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
     private:
    int length(ListNode* head)
    {int count=0;
        ListNode* temp=new ListNode();
        temp=head;
        while(temp)
        {temp=temp->next;
        count++;}
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
        return head;
        int j=length(head)-k%length(head);
        ListNode*p=new ListNode();
        p=head;
        ListNode*q=new ListNode();
        q=head;
        while(q->next)
        q=q->next;
        q->next=head;
        while(j>1)
       { p=p->next;
        j--;}
        head=p->next;
        p->next=NULL;
        return head;

    }
};