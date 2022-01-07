// https://leetcode.com/problems/intersection-of-two-linked-lists/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p = headA, *q = headB;
    while (p and q)
    {
        p = p->next;
        q = q->next;
    }
    while (p)
    {
        headA = headA->next;
        p = p->next;
    }

    while (q)
    {
        headB = headB->next;
        q = q->next;
    }
    while (headA and headB and headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}