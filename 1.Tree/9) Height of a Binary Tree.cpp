//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Time Complexity : O(n)
// Space Complexity : O(h)
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}