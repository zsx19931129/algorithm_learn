class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for(int i=0;i<n-1;i++){
            int min = A[i];
            int idx = i;
            for(int j=i+1;j<n;j++){
                if(min>A[j]){
                    min = A[j];
                    idx = j;
                }
            }
            int temp = A[i];
            A[i] = A[idx];
            A[idx] = temp;
        }
        return A;
    }
};