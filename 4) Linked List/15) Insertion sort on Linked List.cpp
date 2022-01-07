// https://leetcode.com/problems/insertion-sort-list/

ListNode *insertionSortList(ListNode *head)
{
    ListNode *start = new ListNode();
    start->next = head;
    ListNode *curr = head, *prev = start;
    while (curr)
    {
        if (curr->next and curr->val > curr->next->val)
        {
            while (prev->next and (prev->next->val < curr->next->val))
            {
                prev = prev->next;
            }
            ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            prev = start;
        }
        else
            curr = curr->next;
    }
    return start->next;
}