class Solution {
public:
    // Helper function to check if there's a path in the binary tree that matches the linked list
    bool dfs(ListNode* head, TreeNode* node) {
        if (head == nullptr) return true;  // If we reached the end of the list, it's a match
        if (node == nullptr) return false; // If we reached a leaf node in the tree, but not the end of the list, it's not a match
        if (head->val != node->val) return false; // If the values don't match, it's not a match

        // Check recursively for both left and right subtrees
        return dfs(head->next, node->left) || dfs(head->next, node->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false; // If the tree is empty, the linked list cannot be a subpath
        // Check if the linked list is a subpath starting from the current node
        // Or any of the subtrees (left or right)
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
