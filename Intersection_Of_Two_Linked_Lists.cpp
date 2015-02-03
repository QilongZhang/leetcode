/*************************************************************************
	> File Name: Intersection_Of_Two_Linked_Lists.cpp
	> Author: QilongZhang
	> Mail: Speknight4534@gmail.com
	> Created Time: 2015年02月03日 星期二 17时46分26秒
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int Alen = 0, Blen = 0;
        ListNode *hA = headA, *hB = headB;
        while(hA){
            hA = hA->next;
            ++Alen;
        }
        while(hB){
            hB = hB->next;
            ++Blen;
        }
        hA = headA, hB = headB;
        if(Alen < Blen){
            hA = headB;
            hB = headA;
        }
        for(int i = 0; i < abs(Alen - Blen); ++i){
            hA = hA->next;
        }
        while(hA && hB){
            if(hA == hB){
                return hA;
            }
            hA = hA->next;
            hB = hB->next;
        }
        return NULL;
    }
};
