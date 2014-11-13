/*************************************************************************
	> File Name: Gray_Code.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月13日 星期四 20时36分54秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> grayCode(int n){
        if(n == 0)
            return vector<int>(1, 0);
        vector<int> vi(2);
        vi[0] = 0, vi[1] = 1;
        for(int i = 2; i <= n; ++i){
            int val = 1 << (i-1);
            for(int j = vi.size() - 1; j >= 0; --j)
                vi.push_back(vi[j] + val);
        }
        return vi;
    }
};

