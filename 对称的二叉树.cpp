//注意这道题不需要建一棵镜像二叉树，只需要对同一棵树，用不同的遍历方式皆可
//另外，Node->val 之前一定要有非空的判断
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
 
    TreeNode* Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return NULL;
        TreeNode* root = new TreeNode(pRoot->val);
        root->left = Mirror(pRoot->right);
        root->right = Mirror(pRoot->left);
        return  root;
    }
    
    bool compare(TreeNode* pRoot,TreeNode* newRoot){
        if(pRoot == NULL&&newRoot==NULL) return true;
        else if(pRoot ==NULL ||newRoot==NULL) return false;
        else if(pRoot->val == newRoot->val){
            return compare(pRoot->left,newRoot->left)&&compare(pRoot->right,newRoot->right);
        }
        else return false;
    }
    
    bool isSymmetrical_(TreeNode* pRoot)
    {
        TreeNode* newRoot=Mirror(pRoot);
        return compare(pRoot,newRoot);
    }
    //书上答案
    bool isSymmetrical(TreeNode* pRoot){
        return isSymmetrical2(pRoot,pRoot);
    }
    
    bool isSymmetrical2(TreeNode* pRoot1,TreeNode* pRoot2){
        if(pRoot1 == NULL&&pRoot2==NULL) return true;
        else if(pRoot1 ==NULL ||pRoot2==NULL) return false;
        else if(pRoot1->val == pRoot2->val){
            return isSymmetrical2(pRoot1->left,pRoot2->right)&&isSymmetrical2(pRoot1->right,pRoot2->left);
        }
        else return false;
    }
    
};
