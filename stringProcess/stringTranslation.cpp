class Translation {
public:
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
    string stringTranslation(string A, int n, int len) {
        // write code here
    	rotateString(A, 0, n-1);
    	rotateString(A, 0, n-len-1);
    	rotateString(A, n-len, n-1);
    	return A;
    }
};