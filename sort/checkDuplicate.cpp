#include <algorithm>
#include <iostream>
using namespace std;

class Checker {
public:
    bool checkDuplicate(vector<int> a, int n) {
        // write code here
        make_heap(a.begin(), a.begin()+n);
        sort_heap(a.begin(), a.begin()+n);

        int curnum = a[0];
        for(int i=1;i<n;++i){
        	if(a[i] == curnum){
        		return true;
        	}else{
        		curnum = a[i];
        	}
        }
        return false;
    }
};