class Solution {
public:
    int MoreThanHalfNum_Solution_(vector<int> numbers) {
        sort(numbers.begin(),numbers.end());
        int count = 0;
        for(int i =0 ; i<numbers.size();i++){
            if(numbers[i] == numbers[numbers.size()/2]) count++;
        }
        if(count >numbers.size()/2) return numbers[numbers.size()/2];
        else return 0;
    }
    //利用count来计数，超过一半的数，一定比其他所有数加起来出现的次数还多
    //count == 0 result 就等于当前数
    int MoreThanHalfNum_Solution(vector<int> numbers){
        int size = numbers.size();
        if(size == 0) return 0;
        int result = numbers[0];
        int count = 1;
        for(int i =0 ;i<size;i++){
            if(count == 0){
                result = numbers[i];
                count++;
            }
            else if(result == numbers[i])
                count++;
            else 
                count--;
        }
        int resCount =0;
        for(int i =0 ; i<size;i++){
            if(numbers[i] == result) resCount++;
        }
        if(resCount>size/2) return result;
        else return 0;
    }
};
