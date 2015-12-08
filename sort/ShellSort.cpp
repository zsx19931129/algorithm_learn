class ShellSort {
public:
    int* shellSort(int* A, int n) {
        // write code here
        for(int gap = n/2; gap > 0; gap /= 2)
        	for(int i = gap; i < n; i++)
        		for(int j = i - gap; j >= 0 && A[j] > A[j+gap]; j -= gap){
        			int temp = A[j];
        			A[j] = A[j + gap];
        			A[j + gap] = temp;
        		}
        return A;
    }
};