/*************************************************************************
	> File Name: Spiral_Matrix.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月07日 星期五 17时12分23秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix){
        int dir = 0;
        int i = 0, j = 0;
        vector<int> vi;
        while(true){
            if(matrix[i][j] == 100000 || i == matrix.size() || j == matrix[0].size() || i == -1 || j == -1)
                break;
            vi.push_back(matrix[i][j]);
            matrix[i][j] = 100000;
            if(dir == 0){//向右运动
                if(j == matrix[0].size() - 1 || matrix[i][j + 1] == 100000){
                    ++i;
                    dir = 1;
                }
                else
                    ++j;
            }
            else if(dir == 1){//向下运动
                if(i == matrix.size() - 1 || matrix[i + 1][j] == 100000){
                    --j;
                    dir = 2;
                }
                else
                    ++i;
            }
            else if(dir == 2){//向左运动
                if(j == 0 || matrix[i][j - 1] == 100000){
                    --i;
                    dir = 3;
                }
                else
                    --j;
            }
            else{
                if(i == 0 || matrix[i - 1][j] == 100000){
                    ++j;
                    dir = 0;
                }
                else
                    --i;
            }
        }
        return vi;
    }
};
