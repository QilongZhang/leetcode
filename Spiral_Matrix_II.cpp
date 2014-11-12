/*************************************************************************
	> File Name: Spiral_Matrix_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月12日 星期三 15时49分11秒
 ************************************************************************/

#include <iostream>
#include <vector>


using namespace std;

class Solution{
protected:
    void GM(vector<vector<int> > &vvi, vector<vector<bool> >&vvb, int n, int row, int col, int dir, int cut){
        if(cut > n*n)
            return;
        vvi[row][col] = cut;
        vvb[row][col] = true;
        if(dir == 0){
            if(col == n - 1 || vvb[row][col + 1])
                GM(vvi, vvb, n, row + 1, col , 1, cut + 1);
            else
                GM(vvi, vvb, n, row, col + 1, 0, cut + 1);
        }
        else if(dir == 1){
            if(row == n - 1 || vvb[row + 1][col])
                GM(vvi, vvb, n, row, col - 1, 2, cut + 1);
            else
                GM(vvi, vvb, n, row + 1, col, 1, cut + 1);
        }
        else if(dir == 2){
            if(col == 0 || vvb[row][col - 1])
                GM(vvi, vvb, n, row - 1, col, 3, cut + 1);
            else
                GM(vvi, vvb, n, row, col - 1, 2, cut + 1);
        }
        else{
            if(row == 0 || vvb[row - 1][col])
                GM(vvi, vvb, n, row, col + 1, 0, cut + 1);
            else
                GM(vvi, vvb, n, row - 1, col, 3, cut + 1);
        }
    }

public:
    vector<vector<int> > generateMatrix(int n){
        vector<vector<int> > vvi(n, vector<int>(n, 0));
        vector<vector<bool> > vvb(n, vector<bool>(n, false));
        if(n)
            GM(vvi, vvb, n, 0 , 0, 0, 1);
        return vvi;
    }
};

int main(){
    Solution st;
    vector<vector<int> > vvi = st.generateMatrix(1);
    for(int i = 0; i < vvi.size(); ++i)
        for(int j = 0; j < vvi[i].size(); ++j)
            cout<<vvi[i][j]<<' ';
    return 0;
}
