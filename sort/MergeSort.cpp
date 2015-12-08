class MergeSort {
public:
    void mergeSortImpl(int* A, int i, int j){
        if(i==j){
            return;
        }
        if(i == j-1){
            if(A[i]>A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            return ;
        }
        int mid = (i+j)/2;
        mergeSortImpl(A, i, mid-1);
        mergeSortImpl(A, mid, j);
        merge(A, i, j, mid);
    }
    void merge(int* A, int l, int r, int mid){
        int len1 = mid-1 - l + 1;
        int len2 = r-mid + 1;
        int* B = new int[len1];
        for(int i=0;i<len1;i++){
            B[i] = A[i + l];
        }
         
        int offset = l;
        int i=0;
        int j=0;
        for(;i<len1&&j<len2;){
            int aidx = j + mid;
            if(B[i]<A[aidx]){
                A[offset++] = B[i];
                i++;
            }else{
                A[offset++] = A[aidx];
                j++;
            }
        }
        while(i<len1){
            A[offset++] = B[i];
            i++;
        }
        while(j<len2){
            A[offset++] = A[j+mid];
            j++;
        }
        delete[] B;
    }
    int* mergeSort(int* A, int n) {
        // write code here
        mergeSortImpl(A, 0, n-1);
        return A;
    }
};