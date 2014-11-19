/*************************************************************************
	> File Name: Reverse_Linked_List_II.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月20日 星期四 07时12分25秒
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
    ListNode *reverseBetween(ListNode *head, int m, int n){
        ListNode lN(-1);
        ListNode *pre = &lN, *pt = head;
        lN.next = head;
        for(int count = 1; pt != NULL && count != n; pt = pt->next, ++count){
            if(count < m)
                pre = pre->next;
        }
        ListNode *pp = pt->next;
        for(ListNode *tmp = pre->next; pp != pt;){
            ListNode *tn = tmp->next;
            tmp->next = pp;
            pp = tmp;
            tmp = tn;
        }
        pre->next = pt;
        return lN.next;
    }
};
