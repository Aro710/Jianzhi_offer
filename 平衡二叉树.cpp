class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
       if(pRoot == NULL) return 0;
       int left = TreeDepth(pRoot->left);
       int right  = TreeDepth(pRoot->right);
       int depth = (left>=right)?left:right;
       return 1+ depth;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        int leftDepth = TreeDepth(pRoot->left);
        int rightDepth = TreeDepth(pRoot->right);
        if(leftDepth-rightDepth>1||leftDepth-rightDepth<-1)
            return false;
        else return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
        ;
    }
};
