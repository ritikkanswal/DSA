// https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(ListNode *node)
{
    swap(node->next->val, node->val);
    ListNode *temp = node->next;
    node->next = node->next->next;
    delete temp;
}