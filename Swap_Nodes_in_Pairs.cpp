/*************************************************************************
	> File Name: Swap_Nodes_in_Pairs.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 16时15分28秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *swapPairs(ListNode *head){
        if(head==NULL || head->next == NULL)
            return head;
        ListNode *p = head, *ret = head->next, *pre = head;
        while(p && p->next != NULL){
            ListNode *p2 = p->next;
            ListNode *p3 = p2->next;
            p2->next = p;
            p->next = p3;
            if(p != head)
                pre->next = p2;
            pre = p;
            p = p3; 
        }
        return ret;
    }
};


