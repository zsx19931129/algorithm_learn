/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        if(k<2 || !head || head->next == NULL){
        	return head;
        }
        ListNode *newHead = NULL, *preLast = NULL;
        ListNode *front = head, *tail = front;
        int cnt = 0;
        while(tail){
        	++cnt;
        	if(cnt == k){
        		ListNode *ptAhead = front->next;
        		ListNode *ptBehind = front;
        		ListNode *nxtFirst = tail->next;
        		while(ptAhead != nxtFirst){
        			ListNode *tmp = ptAhead->next;
        			ptAhead->next = ptBehind;
        			ptBehind = ptAhead;
        			ptAhead = tmp;
        		}
        		if(preLast == NULL){
        			newHead = tail;
        		}else{
        			preLast->next = tail;
        		}
        		front->next = nxtFirst;
        		preLast = front;
        		front = tail = nxtFirst;
        		cnt = 0;
        	}else{
        		tail = tail->next;
        	}
        }
        return newHead;
    }
};