// https://leetcode.com/problems/middle-of-the-linked-list/

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}