class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        // write code here
    	stack<pair<int, int> > stackLeft;
    	stack<pair<int, int> > stackRight;
    	vector<pair<int, int> > biggerLeft(n);
    	vector<pair<int, int> > biggerRight(n);
    	stackLeft.push(make_pair(INT_MAX, -1) );
    	stackRight.push(make_pair(INT_MAX, -1) );
    	for(int i=0;i<n;++i){
    		// 假定所有的值都不可能会超过INT_MAX
    		while(stackLeft.top().second<A[i]){
    			stackLeft.pop();
    		}
    		biggerLeft[i] = stackLeft.top();
    		stackLeft.push(make_pair(i, A[i]));
    	}
    	for(int i=n-1;i>=0;--i){
    		while(stackRight.top().second<A[i]){
    			stackRight.pop();
    		}
    		biggerRight[i] = stackRight.top();
    		stackRight.push(make_pair(i, A[i]));
    	}

    	vector<int> res;
    	for(int i=0;i<n;++i){
    		if(biggerLeft[i].second < biggerRight[i].second){
    			res.push_back(biggerLeft[i].first);
    		}else if(biggerLeft[i].second > biggerRight[i].second){
    			res.push_back(biggerRight[i].first);
    		}else{
    			res.push_back(-1);
    		}
    	}
    	return res;
    }
};