class CountingSort {
public:
    int* countingSort(int* A, int n) {
        // write code here
        int min, max;
        if(n>1)
            min = max = A[0];
        else
            return A;
        for(int i=1;i<n;i++){
            if(min > A[i])
                min = A[i];
            if(max < A[i])
                max = A[i];
        }
        int base = max - min + 1;
        int* cnt = new int[base];
        for(int i=0;i<base;i++){
            cnt[i]=0;
        }
        for(int i=0;i<n;i++){
            cnt[A[i] - min]++;
        }
        int offset = 0;
        for(int i=0;i<base;i++){
            for(int j=cnt[i];j;j--)
                A[offset++] = i + min;
        }
        delete cnt;
        return A;
    }
};