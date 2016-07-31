#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <climits>
using namespace std;



 struct ListNode {
 int val;
 struct ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };
class InsertValue {
public:
    inline ListNode* constructList(const vector<int> &A, const vector<int> &nxt, int vlen){
        ListNode *head = new ListNode(A[0]);
        ListNode *cur = head;
        for(int i=1;i<vlen;++i){
            cur->next = new ListNode(A[nxt[i-1]]);
            cur = cur->next;
        }
        cur->next = head;
        return head;
    }
    inline ListNode* insertList(ListNode *head, int val){
        if(val<=head->val){
            ListNode *tmp = new ListNode(head->val);
            tmp->next = head->next;
            head->next = tmp;
            head->val = val;
            return head;
        }
        ListNode *cur = head->next;
        while(val > cur->val){
            if(cur->next == head){
                ListNode *tmp = new ListNode(val);
                tmp->next = cur->next;
                cur->next = tmp;
                return head;
            }else{
                cur = cur->next;
            }
        }
        ListNode *tmp = new ListNode(cur->val);
        tmp->next = cur->next;
        cur->next = tmp;
        cur->val = val;
        return head;
    }
    ListNode* cycle2single(ListNode *head){
        ListNode *cur = head;
        while(cur->next != head){
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        int vlen = A.size();
        if(vlen == 0){
            ListNode *head = new ListNode(val);
            head->next = head;
            return head;
        }
        ListNode *head = constructList(A, nxt, vlen);
        head = insertList(head, val);
        head = cycle2single(head);
        return head;
    }
};
int main(){
    InsertValue *ut = new InsertValue();
    int arrayA[] = {1,3,4,5,7};
    int arrayNext[] = {1,2,3,4,0};
    int vlen = 5;
    int val = 3;
    vector<int> A(arrayA, arrayA+5);
    vector<int> nxt(arrayNext, arrayNext+5);
//    vector<int> A;
//    A.push_back(2);
//    vector<int> nxt;
//    nxt.push_back(0);
//    int val = 2;
    ListNode *head =  ut->insert(A, nxt, val);
    ListNode *cur = head;
    cout<<cur->val<<" ";
    cur = cur->next;
    while(cur!=NULL){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    return 0;
}