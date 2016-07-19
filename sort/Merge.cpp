#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        // write code here
        int cura = n-1;
        int curb = m-1;
        int curm = n + m - 1;
        while(cura >=0 && curb >= 0){
            if(A[cura] >= B[curb]){
                A[curm] = A[cura];
                --cura;
            }else{
                A[curm] = B[curb];
                --curb;
            }
            --curm;
        }
        while(curb>=0){
            A[curm] = B[curb];
            --curb;
            --curm;
        }
        return A;
    }
};


int main(){
    Merge* ut = new Merge();
    int A[] = {2, 4, 5, 8, 0, 0, 0, 0, 0};
    int B[] = {1, 3, 6, 7};
    int n=4, m=4;
    ut->mergeAB(A, B, 4, 4);
    for(int i=0;i<n+m;++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
