/*************************************************************************
	> File Name: Insert_Interval.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月07日 星期五 15时51分30秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e){}
};

class Solution{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
        int pos = 0;
        while(pos < intervals.size() && newInterval.start <= newInterval.end){
            if(intervals[pos].start > newInterval.end)
                break;
            else if(intervals[pos].start == newInterval.end || intervals[pos].end >= newInterval.end){
                intervals[pos].start = min(intervals[pos].start, newInterval.start);
                newInterval.start = newInterval.end + 1;
            }
            else if(intervals[pos].end >= newInterval.start){
                intervals[pos].start = min(newInterval.start, intervals[pos].start);
                newInterval.start = intervals[pos].end;
            }
            ++pos;
        }
        if(newInterval.start <= newInterval.end)
            if(pos == intervals.size())
                intervals.push_back(newInterval);
            else
                intervals.insert(intervals.begin() + pos, newInterval);
        vector<Interval> vI;
        int s = -1, e = -1;
        for(int pt = 0; pt < intervals.size(); ++pt){
            if(s == -1 && e == -1)
                s = intervals[pt].start, e = intervals[pt].end;
            else if(intervals[pt].start == e)
                e = intervals[pt].end;
            else{
                vI.push_back(Interval(s, e));
                s = intervals[pt].start, e = intervals[pt].end;
            }
        }
        if(s != -1 || e != -1)
            vI.push_back(Interval(s, e));
        return vI;
    }
};

int main(){
    vector<Interval> vI;
    vI.push_back(Interval(1,2));
    vI.push_back(Interval(3,5));
    vI.push_back(Interval(6,7));
    vI.push_back(Interval(8,10));
    vI.push_back(Interval(12,16));
    Solution st;
    vector<Interval> ret =  st.insert(vI, Interval(4, 6));
    for(int i = 0; i < ret.size(); ++i)
        cout<<ret[i].start<<' '<<ret[i].end<<endl;
    return 0;
}
