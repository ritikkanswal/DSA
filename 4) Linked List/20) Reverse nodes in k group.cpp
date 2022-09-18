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

//Method 1 
// Using auxilary array

// Time Complexity : O(n)
//Space Complexity : O(n)

//Method 2
//without using extra space

// Time Complexity : O(n)
//Space Complexity : O(1)
class Solution {
public:
    // 1 2 3
    
    ListNode * reverse(ListNode *head)
    {
        ListNode *first=NULL,*second=head,*temp=head;
        
        while(second)
        {
            temp=second->next;
            second->next=first;
            first=second;
            second=temp;
        }
        return first;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode* i=dummy;
        ListNode* j=head;
        int val;
        
        while(j!=NULL)
        {
            val=k;
            while(val-- and j!=NULL)
            {
                ListNode * tmp=j->next;
                if(val==0)
                {
                   j->next=NULL; 
                   j=tmp;
                }
                else
                j=j->next;
            }
            if(val>=0)
                break;
            ListNode *tmp=i->next;
            i->next=reverse(i->next);
            tmp->next=j;
            i=tmp;
        }
        
        return dummy->next;
    }
};