//思路是用一个辅助栈，来储存没有输出的元素，然后一直把输出序列跟栈顶比
//相同就输出栈顶，不相同就把下一个元素入栈
class Solution {
public:

    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()&&popV.empty()) return true;
        stack<int> inStack;
        
        while(!popV.empty()){
            if(!inStack.empty()&&inStack.top()==popV[0]){
            inStack.pop();
            popV.erase(popV.begin());
        }
        else if(!pushV.empty()){
            inStack.push(pushV[0]);
            pushV.erase(pushV.begin());
        }
        else return false;
        }
        return true;
}
};
