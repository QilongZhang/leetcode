/*************************************************************************
	> File Name: Search_a_2D_Matrix.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 00时30分41秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target){
        int rst = 0, red = matrix.size() - 1, rmid;
        while(rst < red){
            rmid = (rst + red)/2 + 1;
            if(matrix[rmid][0] <= target)
                rst = rmid;
            else 
                red = rmid - 1;
        }
        int cst = 0, ced = matrix[0].size() - 1, cmid;
        while(cst <= ced){
            cmid = (cst + ced)/2;
            if(matrix[rst][cmid] == target)
                return true;
            else if(matrix[rst][cmid] < target)
                cst = cmid + 1;
            else 
                ced = cmid - 1;
        }
        return false;
    }
};
