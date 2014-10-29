/*************************************************************************
	> File Name: Reverse_Nodes_in_k-Group.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月29日 星期三 18时56分12秒
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
    ListNode *reverseKGrop(ListNode *head, int k){
        if(head == NULL || head->next == NULL ||  k <= 1)
            return head;
        ListNode *ret = head;
        ListNode *p1 = head, *p2 = head, *p3 = head, *pre = head;
        while(p2){
            for(int i = 1; i < k && p2; ++i)
                p2 = p2->next;
            if(p2 == NULL && p1 != head)
                pre->next = p1;
            else if(p2 != NULL){
                if(ret == head)
                    ret = p2;
                if(p1 != head)
                    pre->next = p2;
                pre = p1;
                p3 = p2->next;
                for(ListNode *pp = p3, *lp = p1; pp != p2;){
                    ListNode *tmp = lp->next;
                    lp->next = pp;
                    pp = lp;
                    lp = tmp;
                }
                p2 = p3;
                p1 = p3;
            }   
        }
        return ret;
    }
};
