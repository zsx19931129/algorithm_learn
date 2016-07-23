class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        // write code here
    	int cha[256] = {0};
    	int chb[256] = {0};
    	for(int i=0;i<lena;++i){
    		++cha[A[i]];
    	}
    	for(int i=0;i<lenb;++i){
    		++chb[B[i]];
    	}
    	for(int i=0;i<256;++i){
    		if(cha[i] != chb[i]){
    			return false;
    		}
    	}
    	return true;
    }	
};