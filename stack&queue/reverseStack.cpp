class StackReverse {
public:
	int getLastItemOfStack(vector<int> &A){
		if(A.empty()){
			return ;
		}
		int result = A[A.size()-1];
		A.pop_back();
		if(A.size() == 0){
			return result;
		}else{
			int last = getLastItemOfStack(A);
			A.push_back(result);
			return last;
		}
	}

	void reverse(vector<int> &A){
		int last = getLastItemOfStack(A);
		if(A.size() != 0){
			reverse(A);
		}
		A.push_back(last);
	}

    vector<int> reverseStack(vector<int> A, int n) {
        // write code here
    	reverse(A);
    	return A;
    }
};