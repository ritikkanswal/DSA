// https://leetcode.com/problems/add-two-numbers/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL, *p = NULL;
    int carry = 0;
    while (l1 or l2 or carry)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        ListNode *temp = new ListNode(sum % 10);
        if (!head)
        {
            head = temp;
            p = temp;
        }
        else
        {
            p->next = temp;
            p = p->next;
        }
        carry = sum / 10;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return head;
}