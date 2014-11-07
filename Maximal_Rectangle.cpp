/*************************************************************************
	> File Name: Maximal_Rectangle.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月07日 星期五 18时49分58秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximalRectangle(vector<vector<char> > &matrix){
        if(matrix.empty())
            return 0;
        vector<vector<int> > vvi(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = matrix[0].size() - 1; j >= 0; --j){
                if(matrix[i][j] == '1' && j == matrix[0].size() - 1)
                    vvi[i][j] = 1;
                else if(matrix[i][j] == '1')
                    vvi[i][j] = vvi[i][j+1] + 1;
            }
        }
        int ret = 0;
        for(int j = 0; j < vvi[0].size(); ++j){
            for(int i = 0; i < vvi.size(); ++i){
                int l = 0, r = 0;
                for(int m = i - 1; m >= 0 ; --m)
                    if(vvi[m][j] >= vvi[i][j])
                        ++l;
                    else
                        break;
                for(int n = i + 1; n < vvi.size(); ++n)
                    if(vvi[n][j] >= vvi[i][j])
                        ++r;
                    else
                        break;
                ret = max(ret, (1+r+l)*vvi[i][j]);
            }
        }
        return ret;
    }
};
