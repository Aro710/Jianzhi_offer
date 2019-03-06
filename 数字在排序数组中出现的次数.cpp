//用二分查找，找到第一个相等的数
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0) return 0;
        int begin = 0;
        int end = data.size()-1;
        int mid;
        int count =0;
        while(begin<=end){
            mid =(begin+end)/2;
            if(data[mid]>=k) end = mid -1;
            else begin = mid + 1;
        }
            if(data[begin]==k){
        while(data[begin]==k&&begin<data.size()){
            count++;
            begin++;
        }
    }
    return count;
    }
};
