class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                    TreeNode* p,
                                    TreeNode* q) {

        // Both nodes are smaller than root
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Both nodes are greater than root
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // They are on different sides
        // OR root is p OR root is q
        return root;
    }
};