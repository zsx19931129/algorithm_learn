class Reverse {
public:
	enum status{readSpace = 0, readWord};
	inline void swapChar(char &a, char &b){
		char tmp = a;
		a = b;
		b = tmp;
	}
	void rotateString(string &str, int left, int right){
		for(int i=left, j=right;i<j;++i,--j){
			swapChar(str[i], str[j]);
		}
	}
    string reverseSentence(string A, int n) {
        // write code here
    	rotateString(A, 0, n-1);
    	int left=0, right = 0;
    	int i=0, lastSpace = -1;
    	status state = readSpace;
    	while(i<n){
    		if(A[i] == ' '){
    			if(state == readWord){
    				left = lastSpace + 1;
    				right = i - 1;
    				rotateString(A, left, right);
    				state = readSpace;
    				lastSpace = i;
    			}else{
    				lastSpace = i;
    			}
    		}else{
    			if(state == readWord){
    				right = i;
    			}else{
    				left = right = i;
                    state = readWord;
    			}
    		}
    		++i;
    	}
        if(state == readWord){
            rotateString(A, left, right);
        }
    	return A;
    }
};