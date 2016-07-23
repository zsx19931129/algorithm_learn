#include <iostream>
#include <vector>

using namespace std;

class Gap {
public:
    int maxGap(vector<int> A, int n) {
        // write code here
        int min=A[0], max=A[0];
        int vsize = A.size();
        for(int i=1;i<vsize;++i){
            if(min>A[i]){
                min = A[i];
            }
            if(max<A[i]){
                max = A[i];
            }
        }
        vector<double> boundryValues(vsize+1);
        boundryValues[0] = min;
        boundryValues[vsize] = max;
        double diff = (max - min)/vsize;
        for(int i=1;i<vsize;++i){
            boundryValues[i] = boundryValues[i-1] + diff;
        }
        vector<vector<int> > bucket(vsize+1);
        vector<int> minValueBucket(vsize+1, max);
        vector<int> maxValueBucket(vsize+1, min);
        
        for(int i=0;i<vsize;++i){
            int j=0;
            while(j<vsize+1 && A[i]>=boundryValues[j]){
                ++j;
            }
            bucket[j-1].push_back(A[i]);
            if(A[i]>maxValueBucket[j-1]){
                maxValueBucket[j-1] = A[i];
            }
            if(A[i]<minValueBucket[j-1]){
                minValueBucket[j-1] = A[i];
            }
        }
        maxValueBucket[vsize] = minValueBucket[vsize] = max;
        
        int lastMax = maxValueBucket[0];
        int maxDiff = 0;
        for(int i=1;i<vsize+1;++i){
            if(bucket[i].size() != 0){
                int diff = minValueBucket[i] - lastMax;
                if(diff > maxDiff){
                    maxDiff = diff;
                }
                lastMax = maxValueBucket[i];
            }
        }
        return maxDiff;
    }
};

int main(){
    int num[] = {1,2,5,4,6};
    int n=5;
    vector<int> A(num, num+5);
    Gap* ut = new Gap();
    int res = ut->maxGap(A, n);
    cout<<res<<endl;
    return 0;
}