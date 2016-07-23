class Finder {
public:
	inline bool valid(int x, int y, int n, int m){
		return (x>=0 && x<n) && (y>=0 && y<m);
	}
    bool findX(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        int curx = n-1, cury = 0;
        bool find = false;
        while(!find && valid(curx, cury, n, m)){
        	int var = mat[curx][cury];
        	if(x == var){
        		find = true;
        		break;
        	}else if(x < var){
        		--curx;
        	}else if(x > var){
        		++cury;
        	}
        }
        return find;
    }
};