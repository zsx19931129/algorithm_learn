/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        vector<int> res;
        ListNode *pta = headA, *ptb = headB;
        while(pta && ptb){
        	if(pta->val < ptb->val){
        		pta = pta->next;
        	}else if(pta->val > ptb->val){
        		ptb = ptb->next;
        	}else{
        		res.push_back(pta->val);
        		pta = pta->next;
        		ptb = ptb->next;
        	}
        }
        return res;
    }
};