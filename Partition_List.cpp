/*************************************************************************
	> File Name: Partition_List.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2014年11月14日 星期五 03时26分55秒
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
    ListNode *partition(ListNode *head, int x){
        ListNode h1(-1), h2(-1);
        ListNode *ph1 = &h1, *ph2 = &h2;
        while(head){
            if(head->val < x){
                ph1->next = head;
                ph1 = head;
            }
            else{
                ph2->next = head;
                ph2 = head;
            }
            head = head->next;
        }
        ph1->next = h2.next;
        ph2->next = NULL;
        return h1.next;
    }
};
