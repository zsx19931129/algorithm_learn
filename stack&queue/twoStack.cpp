class TwoStack {
public:
	stack<int> pushStack;
	stack<int> popStack;
	int pop(){
		if(popStack.empty()){
			while(!pushStack.empty()){
				int item = pushStack.top();
				pushStack.pop();
				popStack.push(item);
			}
		}
		int ret = popStack.top();
		popStack.pop();
		return ret;
	}
	void push(int val){
		pushStack.push(val);
	}
    vector<int> twoStack(vector<int> ope, int n) {
        // write code here
        vector<int> res;
    	for(int i=0;i<n;++i){
    		int cur = ope[i];
    		if(cur == 0){
    			res.push_back(pop());
    		}else{
    			push(cur);
    		}
    	}
    	return res;
    }
};