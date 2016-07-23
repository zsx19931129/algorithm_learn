class Prior {
public:
	static bool compareStr(string a, string b){
		return a+b < b+a;
	}
    string findSmallest(vector<string> strs, int n) {
        // write code here
        sort(strs.begin(), strs.end(), compareStr);
        stringstream ss;
        for(int i=0;i<strs.size();++i){
        	ss<<strs[i];
        }
        return ss.str();
    }
};