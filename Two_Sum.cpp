/*************************************************************************
	> File Name: Two_Sum.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年09月30日 星期二 18时05分08秒
 ************************************************************************/

class Solution{
protected:
    typedef struct node{
        int pt, val;
        node(int p = 0, int v = 0):pt(p), val(v){}
    }Node;

protected:
    bool mycmp(Node a, Node b){
        return a.val < b.val;
    }

public:
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<Node> Num(numbers.size());
        for(int id = 0; id < numbers.size(); ++id){
            Num[id].pt = id + 1;
            Num[id].val = numbers[id];
        }
        sort(Num.begin(), Num.end(), mycmp);
        int a = 0, b = numbers.size() - 1;
        while(Num[a].val + Num[b].val != target){
            if(Num[a].val + Num[b].val > target){
                --b;
            }
            else if(Num[a].val + Num[b].val < target){
                ++a;
            }
        }
        vector<int> ret;
        if(Num[a].pt > Num[b].pt){
            ret.push_back(Num[b].pt);
            ret.push_back(Num[a].pt);
        }
        else{
            ret.push_back(Num[a].pt);
            ret.push_back(Num[b].pt);
        }
        return ret;
    }
};

