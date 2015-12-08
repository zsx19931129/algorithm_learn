class QuickSort {
public:
    void quickSortImpl(int* A, int l, int r){
        if(l<r){
            // 1. partition
            int i=l, j=r, pivot=A[l];
            while(i<j){
                while(i<j && A[j]>pivot)
                    j--;
                if(i<j)
                    A[i++] = A[j];
                 
                while(i<j && A[i]<pivot)
                    i++;
                if(i<j)
                    A[j--] = A[i];
            }// i==j
             
            A[i] = pivot;
             
            int partition = i;
            //2. divide and conquer
            quickSortImpl(A, l, i-1);
            quickSortImpl(A, i+1, r);
        }
         
    }
    int* quickSort(int* A, int n) {
        // write code here
        quickSortImpl(A, 0, n-1);
        return A;
    }
};