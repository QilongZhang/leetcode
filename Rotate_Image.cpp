/*************************************************************************
	> File Name: Rotate_Image.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 17时19分20秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
protected:
    void trans(int len, int &x, int &y){
        int cx = len/2, cy = len/2;
        int rx = x - cx, ry = y - cy;
        if(len%2 == 0)
            rx = rx>=0?rx+1:rx, ry = ry>=0?ry+1:ry;
        y = cy - rx;
        x = cx + ry;
        if(len%2 == 0)
            x = x>cx?x-1:x, y = y>cy?y-1:y;
    }

public:
    void rotate(vector<vector<int> > &matrix){
        int len = matrix.size();
        for(int i = 0; i <= len/2; ++i){
            for(int j = i; j < len - i - 1; ++j){
                int ii = i, jj = j;
                int t1 = matrix[i][j];
                do{
                    trans(len, ii, jj);
                    int t2 = matrix[ii][jj];
                    matrix[ii][jj] = t1;
                    t1 = t2;
                }while(ii != i || jj != j);
            }
        }
    }
};

int main(){
    vector<vector<int> > matrix(8, vector<int>(8,0));
    Solution st;
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            matrix[i][j] = j;
    for(int k = 0; k < 8; ++k){
        for(int l = 0; l < 8; ++l)
            cout<<matrix[k][l]<<' ';
        cout<<endl;   
    }
    cout<<endl;
    st.rotate(matrix);
    for(int k = 0; k < 8; ++k){
        for(int l = 0; l < 8; ++l)
            cout<<matrix[k][l]<<' ';
        cout<<endl;
    }
}
