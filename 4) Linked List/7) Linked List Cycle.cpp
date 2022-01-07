// https://leetcode.com/problems/linked-list-cycle/

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (slow and fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}