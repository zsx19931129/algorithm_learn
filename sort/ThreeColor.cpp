#include <iostream>
#include <vector>

using namespace std;

class ThreeColor {
public:
    inline void swap(vector<int> &A, int a, int b){
        int tmp = A[a];
        A[a] = A[b];
        A[b] = tmp;
    }
    
    inline int findFirstNotZero(vector<int> &A, int cur){
        while(A[cur] == 0){
            ++cur;
        }
        return cur;
    }
    
    inline int findFirstNotTwo(vector<int> &A, int cur){
        while(A[cur] == 2){
            --cur;
        }
        return cur;
    }
    
    vector<int> sortThreeColor(vector<int> A, int n) {
        // write code here
        int left = findFirstNotZero(A, 0);
        int right = findFirstNotTwo(A, n-1);
        int cur = left;
        while(left < right){
            if(A[cur] == 0){
                swap(A, left, cur);
                left = findFirstNotZero(A, left+1);
                if(left > cur){
                    cur = left;
                }
            }
            if(A[cur] == 2){
                swap(A, cur, right);
                right = findFirstNotTwo(A, right-1);
                if(right < cur){
                    break;
                }
            }
            if(A[cur] == 1){
                ++cur;
                if(cur>right){
                    break;
                }
            }
        }
        
        return A;
    }
};

int main(){
    ThreeColor* ut = new ThreeColor();
    int a[] = {0,1,0,1,2,2,0,0,1};
    int n = 9;
    vector<int> A(a, a+9);
    A = ut->sortThreeColor(A, n);
    for(int i=0;i<A.size();++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}