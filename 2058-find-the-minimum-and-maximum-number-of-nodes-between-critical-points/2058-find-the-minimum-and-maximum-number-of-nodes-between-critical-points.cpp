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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr)return {-1,-1};
        int first=-1;
        int cnt=1;
        int maximum=-1;
        int minimum=INT_MAX;
        int pre=head->val;
        int  precnt=-1;
        head=head->next;
        while(head && head->next){
            int curr=head->val;
            int next=head->next->val;
            if((pre>curr && curr<next) ||(pre<curr && curr>next)){
                if(precnt==-1){
                    first=cnt;
                    precnt=cnt;
                }
                else{
                    minimum=min(minimum,cnt-precnt);
                    precnt=cnt;
                }
            }
            pre=head->val;
            cnt++;
            head=head->next;
        }
        if(minimum==INT_MAX)return {-1,-1};
        else return {minimum,precnt-first};
    }
};