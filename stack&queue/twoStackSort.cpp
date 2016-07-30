#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        vector<int> res;
        stack<int> help;
        int vlen = numbers.size();
        if(vlen == 0){
            return res;
        }
        int pivot = numbers[0];
        for(int i=1;i<vlen;++i){
            int item = numbers[i];
            if(item<=pivot){
                int cur = i;
                while(!help.empty()){
                    int helptop = help.top();
                    if(helptop<=item){
                        break;
                    }
                    numbers[cur--] = helptop;
                    help.pop();
                }
                help.push(item);
                while(cur != i){
                    help.push(numbers[++cur]);
                }
            }else{
                help.push(pivot);
                pivot = item;
            }
        }
        help.push(pivot);
        
        while(!help.empty()){
            int item = help.top();
            help.pop();
            res.push_back(item);
        }
        return res;
    }
};
int main(){
    TwoStacks* ut = new TwoStacks();
    int num[] = {3,4,2,5,1};
    int n=5;
    vector<int> A(num, num+n);
    vector<int> res = ut->twoStacksSort(A);
    cout<<"end"<<endl;
    return 0;
}