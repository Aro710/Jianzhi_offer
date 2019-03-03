//如果只用一个seq来记录，并且用的是&seq，注意要在函数后pop（）
//也就是失败后pop
//这题要求我返回的list要从大到小排序，我没排也过了
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
    void equal(TreeNode* root,int expectNumber,vector<int>seq,vector<vector<int> > &path){
        if(expectNumber<0||root==NULL) return ;
        seq.push_back(root->val);
        if(root->val==expectNumber&&root->left==NULL&&root->right==NULL){
            path.push_back(seq);
            return ;
        }
        expectNumber=expectNumber-root->val;    
        if(root->left!=NULL) equal(root->left,expectNumber,seq,path);
        if(root->right!=NULL) equal(root->right,expectNumber,seq,path);
        
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> >path;
        vector<int>seq;
        equal(root,expectNumber,seq,path);
        return path;
    }
};
