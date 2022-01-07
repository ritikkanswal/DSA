// https://leetcode.com/problems/merge-two-sorted-lists/

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *start = new ListNode();
    ListNode *p = start;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return start->next;
}