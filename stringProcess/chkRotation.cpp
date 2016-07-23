class Rotation {
public:
	vector<int> getNextVec(string pattern, int plen){
		int j=0;
		vector<int> next(plen);
		next[0] = -1;
		int k=-1;
		while(j<plen-1){
			if(k == -1 || pattern[j] == pattern[k]){
				++j, ++k;
				if(pattern[j] == pattern[k]){
					next[j] = next[k];
				}else{
					next[j] = k;
				}
			}else{
				k = next[k];
			}
		}
		return next;
	}

	bool kmp(string str, int slen, string pattern, int plen){
		vector<int> next = getNextVec(pattern, plen);
		int j=0, k=0;
		while(j<slen && k<plen){
			if(k == -1 || str[j] == pattern[k]){
				++j, ++k;
			}else{
				k = next[k];
			}
		}
		return k == plen;
	}

    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
    	string merge = A + A;
    	return kmp(merge, lena+lenb, B, lenb);
    }
};