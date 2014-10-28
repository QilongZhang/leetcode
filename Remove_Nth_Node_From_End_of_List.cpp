/*************************************************************************
	> File Name: Remove_Nth_Node_From_End_of_List.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年10月28日 星期二 21时56分48秒
 ************************************************************************/

#include <iostream>

using namespace std;

struct listNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
        ListNode *p1 = head, *p2 = head, *p3 = head;
        for(int i = 1; i < n; ++i)
            p3 = p3->next;
        while(p3->next != NULL){
            p1 = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        if(p1 == p2)
            return head->next;
        p1->next = p2->next;
        return head;
    }
};
