/*************************************************************************
	> File Name: 4Sum.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 09时22分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
protected:
    typedef struct node{
        int sum, p1, p2;
        node(int x, int y, int z) : sum(x), p1(y), p2(z){}
    }Node;

    static bool my_cmp(const Node &a, const Node &b){
        return a.sum < b.sum;
    }

    static bool my_cmp2(const vector<int> &a, const vector<int> &b){
        if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2])
            return a[3] < b[3];
        else if(a[0] == b[0] && a[1] == b[1])
            return a[2] < b[2];
        else if(a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }

public:
    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<Node> vn;
        vector<vector<int> > vvi;
        vector<vector<int> > ret;
        for(int i = 0; i < num.size(); ++i)
            for(int j = i + 1; j < num.size(); ++j)
                vn.push_back(Node(num[i]+num[j], i, j));
        sort(vn.begin(), vn.end(), my_cmp);
        for(int j = 0, k = vn.size() - 1; j < k;){
            if(vn[j].sum + vn[k].sum == target){
                for(int m = j; vn[m].sum == vn[j].sum && m < k; ++m){
                    if(vn[m].p1 != vn[k].p1 && vn[m].p2 != vn[k].p1 && vn[m].p1 != vn[k].p2 && vn[m].p2 != vn[k].p2){
                        vector<int> vi;
                        vi.push_back(num[vn[m].p1]), vi.push_back(num[vn[m].p2]), vi.push_back(num[vn[k].p1]), vi.push_back(num[vn[k].p2]);
                        sort(vi.begin(), vi.end());
                        vvi.push_back(vi);
                    }
                }
                for(int n = k; vn[n].sum == vn[k].sum && j < n; --n){
                    if(vn[j].p1 != vn[n].p1 && vn[j].p2 != vn[n].p1 && vn[j].p1 != vn[n].p2 && vn[j].p2 != vn[n].p2){
                        vector<int> vi;
                        vi.push_back(num[vn[j].p1]), vi.push_back(num[vn[j].p2]), vi.push_back(num[vn[n].p1]), vi.push_back(num[vn[n].p2]);
                        sort(vi.begin(), vi.end());
                        vvi.push_back(vi);                    
                    }
                }                
                ++j;
                --k;
            }
            else if(vn[j].sum + vn[k].sum < target){
                ++j;
            }
            else{
                --k;
            }
        }
        sort(vvi.begin(), vvi.end(),my_cmp2);
        for(int pt = 0, pc = -1; pt < vvi.size(); ++pt, ++pc){
            if(pc != -1 && vvi[pt] == vvi[pc])
                continue;
            ret.push_back(vvi[pt]);
        }
        return ret;
    }
};

int main(){
    Solution st;
    vector<int> vi(4);
    vi[0] = 0, vi[1] = 0, vi[2] = 0, vi[3] = 0;
    vector<vector<int> > vvi = st.fourSum(vi, 0);
    for(int i = 0; i < vvi.size(); ++i){
        for(int j = 0; j < vvi[i].size(); ++j)
            cout<<vvi[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
