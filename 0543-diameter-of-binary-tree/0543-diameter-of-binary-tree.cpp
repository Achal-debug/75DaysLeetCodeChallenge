// Day 39 - 75 Days LeetCode Challenge

class Solution {
public:
    int diameter = 0;

    int depth(TreeNode* root){
        if(root == NULL) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};