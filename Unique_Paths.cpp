/*************************************************************************
	> File Name: Unique_Paths.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月12日 星期三 16时28分44秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){
        vector<vector<int> > vvi(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == 1 && j == 1)
                    vvi[i][j] = 1;
                else
                    vvi[i][j] = vvi[i - 1][j] + vvi[i][j - 1];
            }
        }
        return vvi[m][n];
    }
};
