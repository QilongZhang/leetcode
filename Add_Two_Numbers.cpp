/*************************************************************************
	> File Name: Add_Two_Numbers.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月25日 星期六 14时47分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *Head = new ListNode(-1);
        ListNode *pt = Head;
        while(l1&&l2){
            pt->next = new ListNode(l1->val + l2->val);
            pt = pt->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1)
            l1 = l2;
        while(l1){
            pt->next = new ListNode(l1->val);
            l1 = l1->next;
            pt = pt->next;
        }
        pt = Head->next;
        while(pt){
            if(pt->val >= 10 && pt->next){
                pt->val -= 10;
                pt->next->val += 1;
            }
            else if(pt->val >=10 && !(pt->next)){
                pt->val -= 10;
                pt->next = new ListNode(1);
            }
            pt = pt->next;
        }
        return Head->next;
    }
};


