/*************************************************************************
	> File Name: Merge_Intervals.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月07日 星期五 18时11分01秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e){}
};

class Solution{
protected:
    static bool my_cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }

public:
    vector<Interval> merge(vector<Interval> &intervals){
        sort(intervals.begin(), intervals.end(), my_cmp);
        int pre = 0, pt = 0;
        for(pt = 1; pt < intervals.size(); ++pt){
            if(intervals[pt].start <= intervals[pre].end)
                intervals[pre].end = max(intervals[pre].end, intervals[pt].end);
            else{
                ++pre;
                intervals[pre] = intervals[pt].start;
                intervals[pre] = intervals[pt].end;
            }
        }
        while(pt != pre + 1){
            intervals.pop_back();
            --pt;
        }
        return intervals;
    }
};

