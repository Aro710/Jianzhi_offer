//BST的后序遍历，最后一个是根结点，
//前面的序列一定是由比根结点小的序列和比根结点大的序列组成
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        if(sequence.size()==1) return true;
        int end = sequence.size()-1;
        int index = 0,end1=0;
        while(sequence[index]<sequence[end]) index++;
        end1 = index ;
        while(sequence[index]>sequence[end]&&index<end) index++;
        if(index == end){
            vector<int>left(sequence.begin(),sequence.begin()+index);
            vector<int>right(sequence.begin()+index,sequence.end()-1);
            
            return ((left.empty()||VerifySquenceOfBST(left))&&(right.empty()||VerifySquenceOfBST(right)));
        }
        else return false;
        return true;
        
    }
};
