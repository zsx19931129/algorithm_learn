#include <iostream>
#include <string>
#include <vector>
using namespace std;


class DistinctSubstring {
public:
    int longestSubstring(string A, int n) {
        // write code here
        vector<int> dpLongIdx(n, -1);
        vector<int> dpPre(256, -1);
        dpPre[A[0]] = 0;
        dpLongIdx[0] = 0;
        for(int i=1;i<n;++i){
            if(dpPre[A[i]] >= dpLongIdx[i-1]){
                dpLongIdx[i] = dpPre[A[i]] + 1;
            }else{
                dpLongIdx[i] = dpLongIdx[i-1];
            }
            dpPre[A[i]] = i;
        }
        int max=1;
        for(int i=0;i<n;++i){
            int len = i- dpLongIdx[i] + 1;
            if(len>max){
                max = len;
            }
        }
        return max;
    }
};

int main(){
    DistinctSubstring* ut = new DistinctSubstring();
    string A = "aabcb";
    int n = 5;
    int res = ut->longestSubstring(A, n);
    
    cout<<res<<endl;
    return 0;
}