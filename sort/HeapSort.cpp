class HeapSort {
public:
    void MaxHeapShiftDown(int* A, int n, int cur){
        int cidx = 2*cur + 1;
        int pidx = cur;
        int temp = A[pidx];
        while(cidx < n){
            if(cidx+1 < n && A[cidx+1] > A[cidx] ){
                cidx++;
            }
             
            if(temp>=A[cidx]){
                break;
            }else{
                A[pidx] = A[cidx];
                pidx = cidx;
                cidx = 2*cidx + 1;
            }
        }
        A[pidx] = temp;
    }
    void CreateMaxHeap(int* A, int n){
        for(int i=n/2-1;i>=0;i--){
            MaxHeapShiftDown(A, n, i);
        }
    }
    void mySwap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    int* heapSort(int* A, int n) {
        // write code here
        CreateMaxHeap(A, n);
        for(int i = n-1;i>=1;i--){
            //mySwap(A[0], A[i]);
            int temp = A[0];
            A[0] = A[i];
            A[i] = temp;
            MaxHeapShiftDown(A, i, 0);
        }
        return A;
    }
};