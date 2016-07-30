#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>

using namespace std;


class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        vector<int> ret;
        deque<pair<int, int> > qmax;
        for(int i=0;i<n;++i){
            if(qmax.size() == 0){
                qmax.push_back(make_pair(i, arr[i]));
            }else{
                pair<int, int> fVal = qmax.front();
                if(fVal.first < i-w+1){
                    qmax.pop_front();
                }
                if(qmax.size() == 0){
                    qmax.push_back(make_pair(i, arr[i]));
                }else{
                    while(qmax.size()>0 && qmax.back().second <= arr[i]){
                        qmax.pop_back();
                    }
                    qmax.push_back(make_pair(i, arr[i]));
                }
            }
            if(i>=w-1){
                ret.push_back(qmax.front().second);
            }
        }
        return ret;
    }
};
int main(){
    SlideWindow* ut = new SlideWindow();
    
    int num[] = {4,3,5,4,3,3,6,7};
    int n = 8;
    int w = 3;
    vector<int> arr(num, num+n);
    
    vector<int> res = ut->slide(arr, n, w);
    cout<<endl;
    return 0;
}