class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        int scnt = 0;
        for(int i=0;i<length;++i){
            if(iniString[i] == ' '){
                ++scnt;
            }
        }
        int newlen = length + scnt*2;
        string newstr(newlen, ' ');
        int cur = newlen - 1;
        for(int i=length-1;i>=0;--i){
            if(iniString[i] == ' '){
                newstr[cur] = '0';
                newstr[cur-1] = '2';
                newstr[cur-2] = '%';
                cur = cur-3;
            }else{
                newstr[cur] = iniString[i];
                --cur;
            }
        }
        return newstr;
    }
};