class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for(int i=1;i<n;i++){
            int cur = A[i];
            for(int j=i-1;j>=0;j--){
                if(cur<A[j]){
                    A[j+1] = A[j];
                    if(j == 0){
                        A[0] = cur;
                    }
                }else{
                    A[j+1] = cur;
                    break;
                }
            }
        }
        return A;
    }
};