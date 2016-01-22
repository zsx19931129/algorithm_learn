class ScaleSort {
public:
	void mySwap(int &a , int &b){
		int temp = a;
		a = b;
		b = temp;
	}
    vector<int> sortElement(vector<int> A, int n, int k) {
        // write code here
    	MinHeap heap(A, k);
    	//k-heap sort
    	// last element do not need to sort
    	for(int i = 0; i<=n-1; i++){
			A[i] = heap.root[0];
    		int newRoot = i + k;
    		if(newRoot>=n){
    			// if the rest of elements less than k, root simply move forward 1
    			mySwap(heap.root[0], heap.root[heap.size - 1]);
    			heap.size -= 1;
    		}else{
    			heap.root[0] = A[newRoot];
    		}
    		heap.shiftDown(0);
    	}
    	return A;
    }
private:
	class MinHeap{
	public:
		int * root;
		int * deleteBackup;
		int size;
		void shiftDown(int cur){
			int cidx = 2*cur + 1;
			int pidx = cur;
			int temp = root[pidx];
			while(cidx < size){
				if(cidx+1 < size && root[cidx + 1] < root[cidx])
					cidx++;
				if(temp<=root[cidx]){
					break;
				}
				else{
					root[pidx] = root[cidx];
					pidx = cidx;
					cidx = 2*cidx + 1;
				}
			}
			root[pidx] = temp;
		}
		MinHeap(const vector<int>& input, int inputSize){
			root = new int[inputSize];
			deleteBackup = root;
			size = inputSize;
			for(int i = 0;i<size; i++){
				root[i] = input[i];
			}

			// build minheap
			for(int i = size/2 - 1; i>=0 ; i--){
				shiftDown(i);
			}
		}
		~MinHeap(){
			delete[] deleteBackup;
		}
	};
};