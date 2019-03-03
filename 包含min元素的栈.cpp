//用一个辅助栈 minStack 来记录Stack 每次push后的min值
// 两个栈的元素总是一样多
#include <assert.h>
class Solution {
private:
    stack<int> minStack;
    stack<int> oriStack;
    //int minValue = -99999999;
    
public:
    void push(int value) {
        oriStack.push(value);
        if(minStack.size() == 0 ||value <minStack.top()) 
            minStack.push(value) ;
        else 
            minStack.push(minStack.top());
    }
    void pop() {
        assert(oriStack.size()>0 && minStack.size()>0);
        oriStack.pop();
        minStack.pop();
    }
    int top() {
        return oriStack.top();
    }
    int min() {
        return minStack.top();
    }
};
