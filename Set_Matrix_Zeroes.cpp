/*************************************************************************
	> File Name: Set_Matrix_Zeroes.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 01时59分10秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void setZeroes(vector<vector<int> > &matrix){
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j)
                if(matrix[i][j] == 0)
                    matrix[i][j] == 1<<30;
        for(int k = 0; k < matrix.size(); ++k)
            for(int l = 0; l < matrix[0].size(); ++l)
                if(matrix[k][l] == 1<<30){
                    matrix[k][l] = 0;
                    for(int m = 0; m < matrix.size(); ++m)
                        if(matrix[m][l] != 1<<30)
                            matrix[m][l] = 0;
                    for(int n = 0; n < matrix[0].size(); ++n)
                        if(matrix[k][n] != 1<<30)
                            matrix[k][n] = 0;
                }
    }
};
