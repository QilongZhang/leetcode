/*************************************************************************
	> File Name: Minimum_Path_Sum.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月12日 星期三 16时54分38秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int> > &grid){
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > vvi(m + 1, vector<int>(n + 1, 1<<30));
        for(int i = 1; i <= m; ++i)
            for(int j= 1; j <= n; ++j)
                if(i == 1 && j == 1)
                    vvi[i][j] = grid[i - 1][j - 1];
                else
                    vvi[i][j] = grid[i-1][j-1] + min(vvi[i - 1][j], vvi[i][j - 1]);
        return vvi[m][n];
    }
};
