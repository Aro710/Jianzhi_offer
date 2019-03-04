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
    
    int MoreThanHalfNum_Solution(vector<int> numbers){
        int size = numbers.size();
        int* num =new int[size+1];
        memset(num,0,size+1);
        for(int i = 0; i <size;i++){
            num[numbers[i]]++;
            if(num[numbers[i]]>size/2) return numbers[i];
        }
        return 0;
    }
};
