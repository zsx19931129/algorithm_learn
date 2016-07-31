/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
	inline void insertNode(ListNode* &head, ListNode* &tail, ListNode* &cur){
		if(head == NULL){
			head = tail = cur;
			cur = cur->next;
			tail->next = NULL;
		}else{
			tail->next = cur;
			cur = cur->next;
			tail = tail->next;
			tail->next = NULL;
		}
	}
    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        if(!head){
        	return NULL;
        }
        ListNode *hsmall = NULL, *hequal = NULL, *hbig = NULL;
        ListNode *tsmall = NULL, *tequal = NULL, *tbig = NULL;
        ListNode *cur = head;
        while(cur){
        	if(cur->val <= val){
        		insertNode(hsmall, tsmall, cur);
        	}
        	// else if(cur->val == val){
        		// insertNode(hequal, tequal, cur);
        	// }
        	else{
        		insertNode(hbig, tbig, cur);
        	}
        }
        if(hsmall){
        	if(hequal){
	        	tsmall->next = hequal;
	        	if(hbig){
	        		tequal->next = hbig;
	        	}
	        }else if(hbig){
	        	tsmall->next = hbig;
        	}
        	return hsmall;
        }else if(hequal){
        	if(hbig){
        		tequal->next = hbig;
        	}
        	return hequal;
        }else{
        	return hbig;
        }
    }
};