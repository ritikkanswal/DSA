// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *p = head, *q = head;
    ListNode *first = head;
    while (--k)
    {
        p = p->next;
    }
    first = p;
    while (p and p->next)
    {
        p = p->next;
        q = q->next;
    }
    swap(first->val, q->val);
    return head;
}