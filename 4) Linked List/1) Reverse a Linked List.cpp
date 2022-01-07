// https://leetcode.com/problems/reverse-linked-list/

ListNode *reverseList(ListNode *head)
{
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