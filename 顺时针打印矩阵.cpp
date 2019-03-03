//本题的重点是分清各方向走的特殊情况
//以及把一个矩阵划分位外面的一个框，和里面的一个矩阵
class Solution {
public:
    void myprint(vector<vector<int> > matrix,vector<int>&out,int row,int col,int start){
        //if(row<0||colLen<0) return;
        int endX = col -start-1;
        int endY = row -start -1;
        for(int i =start ;i<=endX;i++)
            out.push_back(matrix[start][i]);
        //大于一行的时候才会向下走
        if(start<endY){
            for(int i = start+1;i<=endY;i++)
                out.push_back(matrix[i][endX]);
        }
        //大于一行且大于1列的时候才会向左走
        if(start<endX&&start<endY){
            for(int i = endX-1;i>=start;i--)
                out.push_back(matrix[endY][i]);
        }
        //大于两行且大于一列的时候，才会向上走
        if(start<endX&&start<endY-1){
            for(int i = endY-1;i>start;i--)
                out.push_back(matrix[i][start]);
        }
        
    }
    

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> out;
        if(matrix.empty()) return out;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int start=0;
        while(colLen>start*2&&rowLen>start*2)
        myprint(matrix , out,rowLen,colLen,start++);
        return out;
    }
};
