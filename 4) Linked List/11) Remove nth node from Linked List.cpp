// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *p = head, *q = head, *prev = head;
    while (n--)
    {
        p = p->next;
    }
    while (p and p->next)
    {
        p = p->next;
        q = q->next;
    }
    ListNode *temp;
    if (p)
    {
        temp = q->next;
        q->next = q->next->next;
    }
    else
    {
        temp = head;
        head = head->next;
    }
    delete (temp);
    return head;
}