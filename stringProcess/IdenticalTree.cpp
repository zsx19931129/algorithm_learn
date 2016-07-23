#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class IdenticalTree {
public:
    string serializaByPre(TreeNode* root){
        if(!root){
            return "#!";
        }else{
            return "#" + to_string(root->val) + serializaByPre(root->left) + serializaByPre(root->right);
        }
    }
    
    vector<int> getNextVal(string pattern){
        int plen = pattern.length();
        vector<int> next(plen);
        // calculate next[0]..next[j]..next[plen-1]
        int j=0;
        next[0] = -1;
        // k == next[j-1]
        int k=-1;
        //只用求剩下的plen-1个
        while(j<plen-1){
            if(k == -1 || pattern[k] == pattern[j]){
                ++k, ++j;
                // 此时已经执行了++操作
                if(pattern[j] == pattern[k]){
                    next[j] = next[k];
                }else{
                    next[j] = k;
                }
            }else{
                // 利用已经计算出的next向量继续优化
                k = next[k];
            }
        }
        return next;
    }
    
    bool kmp(string str, string pattern){
        vector<int> next = getNextVal(pattern);
        int slen = str.length();
        int plen = pattern.length();
        int j=0, k=0;
        while(j<slen && k<plen){
            if(k == -1 || str[j] == pattern[k]){
                ++j,++k;
            }else{
                k = next[k];
            }
        }
        return k == plen;
    }
    
    bool chkIdentical(TreeNode* A, TreeNode* B) {
        // write code here
        // O(m+n)
        string serialA = serializaByPre(A);
        string serialB = serializaByPre(B);
        return kmp(serialA, serialB);
    }
};

int main(){
    TreeNode* A = new TreeNode(2);
    A->left = new TreeNode(5);
    A->right = new TreeNode(6);
    A->left->left = new TreeNode(7);
    A->left->right = new TreeNode(8);
    
    TreeNode* B1 = new TreeNode(5);
    B1->left = new TreeNode(7);
    B1->right = new TreeNode(8);
    
    TreeNode* B2 = new TreeNode(5);
    B2->left = new TreeNode(7);
    
    IdenticalTree* ut = new IdenticalTree();
    assert(ut->chkIdentical(A, B1));
    assert(!(ut->chkIdentical(A, B2)));
    return 0;
}