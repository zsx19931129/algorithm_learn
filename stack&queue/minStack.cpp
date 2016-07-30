class Solution {
public:
	stack<int> data;
	stack<int> minval;
    void push(int value) {
        data.push(value);
        if(minval.empty()){
        	minval.push(value);
        }else{
        	int top = std::min(value, minval.top());
        	minval.push(top);
        }
    }
    void pop() {
        if(data.empty()){
        	return ;
        }
        data.pop();
        minval.pop();
    }
    int top() {
    	if(data.empty()){
    		return -1;
    	}
        return data.top();
    }
    int min() {
    	if(minval.empty()){
    		return -1;
    	}
    	return minval.top();
    }
};