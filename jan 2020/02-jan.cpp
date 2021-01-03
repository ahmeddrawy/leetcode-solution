//
// Created by ahmeddrawy on 1/2/2021.
// assuming that all nodes are unique

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned->val == target->val){
            return cloned;
        }
        if(cloned->right == NULL && cloned->left== NULL)
            return NULL;
        if(cloned->left != NULL){
            TreeNode * l = cloned->left;
            TreeNode * ret = getTargetCopy(original , l , target);
            if(cloned->right != NULL){
                TreeNode * r = cloned->right;
                if(ret == NULL)
                    return getTargetCopy(original , r , target);

            }

            return ret;
        }
        else {
            TreeNode * r = cloned->right;
            return getTargetCopy(original , r , target);
        }
    }

};