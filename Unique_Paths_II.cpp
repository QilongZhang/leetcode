/*************************************************************************
	> File Name: Unique_Paths_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月12日 星期三 16时39分35秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > vvi(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(obstacleGrid[i - 1][j - 1])
                    vvi[i][j] = 0;
                else if(i == 1 && j == 1)
                    vvi[i][j] = 1;
                else
                    vvi[i][j] = vvi[i - 1][j] + vvi[i][j - 1];
            }
        }
        return vvi[m][n];
    }
};

