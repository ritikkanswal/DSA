// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Method-1
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *p = head;
    while (p and p->next)
    {
        if (p->val == p->next->val)
        {
            ListNode *temp = p->next;
            p->next = temp->next;
            delete (temp);
        }
        else
            p = p->next;
    }
    return head;
}