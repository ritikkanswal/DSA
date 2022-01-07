// https://leetcode.com/problems/swap-nodes-in-pairs/


ListNode *swapPairs(ListNode *head)
{
    if (!head or !head->next)
        return head;
    ListNode *p = head, *prev = NULL;
    while (p and p->next)
    {
        ListNode *temp = p->next;
        p->next = p->next->next;
        temp->next = p;
        if (!prev)
        {
            head = temp;
            prev = temp;
        }
        else
            prev->next = temp;
        prev = p;
        p = p->next;
    }
    return head;
}