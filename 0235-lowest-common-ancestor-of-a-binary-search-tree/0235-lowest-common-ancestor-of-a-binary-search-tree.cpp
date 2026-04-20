// Day 40 - 75 Days LeetCode Challenge
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {

        while(r != NULL){

            if(p->val < r->val && q->val < r->val){
                r = r->left;
            }
            else if(p->val > r->val && q->val > r->val){
                r = r->right;
            }
            else{
                return r;
            }
        }

        return NULL;
    }
};