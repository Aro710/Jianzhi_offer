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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*>treeQue;
        if(root==NULL) return result;
        treeQue.push(root);
        while(!treeQue.empty()){
            TreeNode* p = treeQue.front();
            treeQue.pop();
            result.push_back(p->val);
            if(p->left!=NULL) treeQue.push(p->left);
            if(p->right!=NULL) treeQue.push(p->right);
        }
        return result;
        
    }
};
