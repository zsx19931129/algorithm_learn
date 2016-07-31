#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <climits>
#include "LinkedList.h"

using namespace std;

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        if(!pHead || pHead->next == NULL){
            return true;
        }
        ListNode *stepOne = pHead;
        ListNode *stepTwo = pHead;
        bool odd = false;
        while(stepTwo->next){
            stepOne = stepOne->next;
            stepTwo = stepTwo->next;
            odd = false;
            if(stepTwo->next){
                stepTwo = stepTwo->next;
                odd = true;
            }
        }
        ListNode *rhead = NULL, *rtail = NULL;
        if(odd){
            rhead = stepOne->next;
        }else{
            rhead = stepOne;
        }
        rtail = stepTwo;
        ListNode *ahead = rhead;
        ListNode *behind = NULL;
        // rhead->next == NULL
        while(ahead){
            ListNode *tmp = ahead->next;
            ahead->next = behind;
            behind = ahead;
            ahead = tmp;
        }
        bool same = true;
        ListNode *pt1 = pHead, *pt2 = stepTwo;
        ListNode *pRecover = NULL;
        while(pt2){
            if(pt1->val != pt2->val){
                same = false;
            }
            ListNode *tmp = pt2->next;
            pt2->next = pRecover;
            pRecover = pt2;
            pt2 = tmp;
            pt1 = pt1->next;
        }
        return same;
    }
};

int main(){
    Palindrome *ut = new Palindrome();
    int arr[] = {1,2,3,2,1};
    int n=5;
    List *lst = new List(arr, n);
    lst->show();
    bool res = ut->isPalindrome(lst->head);
    lst->show();
    cout<<res<<endl;
    return 0;
}