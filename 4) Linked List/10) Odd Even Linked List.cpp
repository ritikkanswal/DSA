// https://leetcode.com/problems/odd-even-linked-list/

ListNode *oddEvenList(ListNode *head)
{
    ListNode *even = NULL, *odd = NULL, *p = head, *HeadEven = NULL;
    int k = 1;
    while (p)
    {
        if (k & 1)
        {
            if (!odd)
                odd = p;
            else
            {
                odd->next = p;
                odd = odd->next;
            }
        }
        else
        {
            if (!even)
            {
                even = p;
                HeadEven = p;
            }
            else
            {
                even->next = p;
                even = even->next;
            }
        }
        p = p->next;
        k++;
    }
    if (even)
        even->next = NULL;
    if (odd)
        odd->next = HeadEven;
    return head;
}