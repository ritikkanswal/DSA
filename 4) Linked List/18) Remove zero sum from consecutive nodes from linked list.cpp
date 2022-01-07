// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Method-1

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    for (ListNode *i = dummy; i; i = i->next)
    {
        int sum = 0;
        for (ListNode *j = i->next; j; j = j->next)
        {
            sum += j->val;
            if (sum == 0)
            {
                i->next = j->next;
            }
        }
    }
    return dummy->next;
}

//Method-2

ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    unordered_map<int, ListNode *> ump;
    int sum = 0;
    for (ListNode *i = dummy; i; i = i->next)
    {
        sum += i->val;
        ump[sum] = i;
    }
    sum = 0;
    for (ListNode *i = dummy; i; i = i->next)
    {
        sum += i->val;
        i->next = ump[sum]->next;
    }
    return dummy->next;
}