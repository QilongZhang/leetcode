/*************************************************************************
	> File Name: Merge_Two_Sorted_Lists.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月08日 星期六 19时21分25秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode Head(-1);
        ListNode *p1 = &Head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p1->next = l1;
                l1 = l1->next;
            }
            else{
                p1->next = l2;
                l2 = l2->next;
            }
            p1 = p1->next;
        }
        if(l2)
            l1= l2;
        while(l1){
            p1->next = l1;
            p1 = l1;
            l1 = l1->next;
        }
        return Head.next;
    }
};
