// https://leetcode.com/problems/split-linked-list-in-parts/

int count(ListNode *head)
{
    int count = 0;
    while (head)
    {
        head = head->next;
        count++;
    }
    return count;
}
vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    int cnt = count(head);
    int val = cnt % k;
    int p = cnt / k;
    vector<ListNode *> res;
    ListNode *q = head;
    while (k--)
    {
        q = head;
        if (!q)
        {
            res.push_back(NULL);
            continue;
        }
        res.push_back(q);
        for (int i = 1; i < (p + val > 0); i++)
            q = q->next;
        val--;
        head = q->next;
        q->next = NULL;
    }
    return res;
}