// https://leetcode.com/problems/copy-list-with-random-pointer

// Method-1
map<Node *, Node *> mp;
Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    Node *p = head, *res;
    while (p)
    {
        mp[p] = new Node(p->val);
        p = p->next;
    }
    p = head;
    while (p)
    {
        mp[p]->next = mp[p->next];
        mp[p]->random = mp[p->random];
        p = p->next;
    }
    return mp[head];
}

//Method-2

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;
    Node *p = head;
    //STEP 1
    while (p)
    {
        Node *tmp = new Node(p->val);
        tmp->next = p->next;
        p->next = tmp;
        p = p->next->next;
    }

    //STEP 2
    p = head;
    while (p)
    {
        if (p->random)
            p->next->random = p->random->next;
        p = p->next->next;
    }

    //STEP 3
    p = head;
    Node *Head = new Node(0);
    Node *res = Head;
    while (p)
    {
        res->next = p->next;
        res = res->next;
        p->next = p->next->next;
        p = p->next;
    }
    return Head->next;
}