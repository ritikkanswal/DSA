// https://leetcode.com/problems/reverse-linked-list/


//Method 1
// using array
// Time Complexity : O(n)
// Space Complexity : O(n)

// Method-2
// Time Complexity : O(n)
// Space Complexity : O(1)
ListNode *reverseList(ListNode *head)
{
    ListNode *first = NULL, *second = head, *temp = NULL;

    while (second)
    {
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }
    return first;
}

// Method-3
// using recursion
// Time Complexity : O(n)
// Space Complexity : O(1)

ListNode *Head=NULL;
void reverse(ListNode * prev,ListNode *curr)
{
    if(curr==NULL)
    {
        Head=prev;
        return;
    } 

    ListNode *temp=curr->next;
    curr->next=prev;

    reverse(curr,temp);
}
ListNode* reverseList(ListNode* head) {
    reverse(NULL,head);
    return Head;
}