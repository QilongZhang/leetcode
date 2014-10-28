/*************************************************************************
	> File Name: Merge_K_Sorted_Lists.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 22时48分00秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
protected:
    ListNode *MKL(vector<ListNode *> &lists, int st, int ed){
        if(st > ed)
            return NULL;
        else if(st == ed)
            return lists[st];
        ListNode *l1 = MKL(lists, st, (st+ed)/2);
        ListNode *l2 = MKL(lists, (st+ed)/2+1, ed);
        ListNode Head(-1);
        ListNode *p = &Head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            p->next = NULL;
        }
        if(l1 == NULL)
            l1 = l2;
        p->next = l1;
        return Head.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists){
       return MKL(lists, 0, lists.size() - 1); 
    }
};

int main(){
    return 0;
}
