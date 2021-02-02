//
// Created by ahmeddrawy on 2/2/21.
//
/** including constructing complete binary tree, printing inOrder
 * trimming Binary search tree to keep only nodes in range,
 * first we make a dummy node and insert root in right
 * then we solve recursively
 * if left
 *      if left.val in range
 *          we go to left
 *      else
 *          we choose what to ignore
 *          if val > high
 *              we ignore right
 *          else
 *              we ignore left
 * we do the same with right
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int low ,high;
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->low = low ;
        this->high = high;
        TreeNode * dummy = new TreeNode(0,NULL,root);
        solve(dummy);
        return dummy->right;
    }
    void solve(TreeNode *root){
        if(root->left == NULL && root->right == NULL)
            return ;
        if(root->left != NULL){
            if(!inRange(root->left->val)){
                if(root->left->val >high){
                    root->left = root->left->left;
                }
                else{
                    root->left = root->left->right;
                }
                solve(root);
            }
            else {
                solve(root->left);
            }
        }
        if(root->right != NULL){
            if(!inRange(root->right->val)){
                if(root->right->val > high){
                    root->right = root->right->left;
                }else{
                    root->right = root->right->right;
                }
                solve(root);
            }else
                solve(root->right);
        }
    }
    bool inRange(int x){
        return !(x<low || x>high);
//        return x>=low && x<=high;
    }
};
TreeNode * constructTree(TreeNode * root , int i,vector<int> & vec){
    if(i<vec.size()){
        TreeNode * tmp = NULL;
        if(vec[i] != -1) tmp = new TreeNode(vec[i]);
        else return root = tmp;
        root = tmp;
        root->left = constructTree(root->left,2*i+1,vec);
        root->right = constructTree(root->right,2*i+2,vec);

    }
    return root;


}
void inOrder(TreeNode * root){
    if(root == NULL)
        return ;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}