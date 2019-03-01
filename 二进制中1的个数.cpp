// 负数用补码表示， 其中符号位为1
// 移位操作不会动符号位，1一直往左移就会变成0

// 第二种方法 利用一个数n与n-1做与操作，那么相当于把n最右边一个1变成0
class Solution {
public:
     int  NumberOf1_(int n) {
         int count = 0;
         unsigned int flag =1;
         while(flag){
             if(n & flag) count++;
             flag = flag <<1;
         }
         return count;
     }
    
    int  NumberOf1(int n) {
         int count = 0;
         //unsigned int flag =1;
         while(n){
             count++;
             n=(n-1)&n;
         }
         return count;
     }
    
};
