// https://leetcode.com/problems/palindrome-linked-list/

ListNode *reverse(ListNode *head)
{
    if (!head)
        return NULL;
    ListNode *first = NULL, *second = head, *temp = NULL;
    while (second)
    {
        temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }
    return first;
}
bool isPalindrome(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast and fast->next and fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    fast = head;
    while (slow)
    {
        if (slow->val != fast->val)
            return 0;
        slow = slow->next;
        fast = fast->next;
    }
    return 1;
}