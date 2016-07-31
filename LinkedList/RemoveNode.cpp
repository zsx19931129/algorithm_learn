/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // write code here
        if(pNode->next == NULL){
        	return false;
        }else{
        	pNode->val = pNode->next->val;
        	ListNode* del = pNode->next;
        	pNode->next = pNode->next->next;
        	delete del;
        	return true;
        }
    }
};