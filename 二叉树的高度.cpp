/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
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
};
