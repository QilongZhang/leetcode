/*************************************************************************
	> File Name: Permutations.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月05日 星期三 15时08分17秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > permute(vector<int> &num){
        vector<vector<int> > vvi;
        vvi.push_back(num);
        int ed = 0;
        for(int i = 1; i < num.size(); ++i){
            for(int j = 0; j < i; ++j){
                for(int k = 0; k <= ed; ++k){
                    vector<int> vi = vvi[k];
                    vi[i] = num[j];
                    for(int m = 0; m < vi.size(); ++m)
                        if(vi[m] == num[j]){
                            vi[m] = num[i];
                            break;
                        }
                    vvi.push_back(vi);
                }
            }
            ed = vvi.size() - 1;
        }
        return vvi;
    }
};

