#include <iostream>
#include <vector>

using namespace std;

class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        // write code here
        // 最大数右边以左需要排序，最小数左边需要排序
        int maxnum = A[0];
        int right = 0;
        for(int i=1;i<n;++i){
            if(A[i]>maxnum){
                maxnum = A[i];
            }else if(A[i]<maxnum){
                right = i;
            }
        }
        int minnum = A[n-1];
        int left = n-1;
        for(int i=n-2;i>=0;--i){
            if(A[i]<minnum){
                minnum = A[i];
            }else if(A[i] > minnum){
                left = i;
            }
        }
        if(right == 0){
            return 0;
        }else{
            return right - left + 1;
        }
        
    }
};

int main(){
    Subsequence* ut = new Subsequence();
    int num[] = {1,2,10,1,8,9};
    int n = 6;
    vector<int> A(num, num+6);
    int res = ut->shortestSubsequence(A, n);
    cout<<res<<endl;
    return 0;
}

