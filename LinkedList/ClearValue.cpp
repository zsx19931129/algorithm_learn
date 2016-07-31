/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        // write code here
        ListNode *cur = head;
        ListNode *newHead = NULL, *newTail = NULL;
        ListNode *pre = NULL;
        while(cur){
        	if(cur->val == val){
        		if(!pre){
        			pre = cur;
        			head = cur;
        		}
        		cur = cur->next;
        	}else{
        		if(pre){
        			pre->next = cur->next;
        		}
        		ListNode *tmp = cur;
        		cur = cur->next;
        		tmp->next = NULL;
        		if(!newHead){
        			newHead = newTail = tmp;
        		}else{
        			newTail->next = tmp;
        			newTail = newTail->next;
        		}
        	}
        }
        return newHead;
    }
};