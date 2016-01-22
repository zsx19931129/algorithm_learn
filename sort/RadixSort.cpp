#include <queue>
using namespace std;

class RadixSort {
public:
    int* radixSort(int* A, int n) {
        // write code here
        queue<int> radix[10];
        queue<int> temp;

        for(int i=0;i<n;i++){
            temp.push(A[i]);
        }

        // units digit, tens digit, hunhreds digit, thousands digit
        for(int factor = 1; factor <= 1000; factor*=10){
            while(!temp.empty()){
                int t = temp.front();
                temp.pop();
                radix[(t/factor)%10].push(t);
            }
            for(int i=0;i<10;i++){
                for(int j=radix[i].size();j;j--){
                    temp.push(radix[i].front());
                    radix[i].pop();
                }
            }
        }
        int offset = 0;
        while(!temp.empty()){
            A[offset++] = temp.front();
            temp.pop();
        }
        return A;
    }
};