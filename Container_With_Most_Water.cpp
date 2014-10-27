/*************************************************************************
	> File Name: Container_With_Most_Water.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月27日 星期一 10时58分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int st = 0, ed = height.size() - 1;
		int ret = 0;
		while(st != ed){
		    ret = max(ret, min(height[st], height[ed]) * (ed - st));
		    if(height[st] >= height[ed])
		        --ed;
		    else
		        ++st;
		}
		return ret;
	}
};
