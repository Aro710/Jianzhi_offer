/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 这道题要注意到：
// 1.字结构代表树上的节点的值相同，而不是地址相同
// 2.字结构可以只是一部分，比如8 是8 6 7 的字结构，递归的时候要注意t2孩子为NULL
// 3.注意空指针的情况以及处理方式
class Solution {
public:
    bool treeCompare(TreeNode* t1,TreeNode* t2){
        if(t1==NULL&&t2!=NULL) return false;
        if(t2==NULL) return true;
        
        if(t1->val!=t2->val)
            return false;
        
        return treeCompare(t1->left,t2->left)&&treeCompare(t1->right,t2->right);
        //return true;
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {   
        if(pRoot1==NULL||pRoot2==NULL) return false;
        if(pRoot1->val==pRoot2->val){
            if(treeCompare(pRoot1,pRoot2)) return true;
            else return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
        }
        return false;

    }
};
