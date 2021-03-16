#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string space(int n){
        string ret = "";
        while(n-->0) ret += " ";
        return ret;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int n = words.size();
        int i=0, j=0;
        while(true){
            int c=0;
            while(j<n){
                c += words[j].size();
                if(c+j-i>maxWidth) break;
                j += 1;
            }
            if(j<n){
                c -= words[j].size();
                j -= 1;
                int balance = maxWidth -c;
                int mn = balance/(j-i);
                int mod = balance%(j-i);
                string mxspace = space(mn+1);
                string mnspace = space(mn);
                string t = "";
                for(int k=i;k<=j-1;k++){
                    if(mod-->0){
                        t += words[k]+mxspace;
                    }else{
                        t += words[k]+ mnspace;
                    }
                }
                t += words[j];
                ret.push_back(t);
                i = j+1;
                j += 1;
            }else{
                j -= 1;
                if(c+j-i<=maxWidth){
                    string t = "";
                    for(int k=i;k<j;k++){
                        t += words[k] + " ";
                    }
                    t += words[j];
                    ret.push_back(t);
                }else{
                    c -= words[j].size();
                    j -= 1;
                    int balance = maxWidth - c;
                    int mn = balance/(j-i);
                    int mod = balance%(j-i);
                    string mxspace = string(" ", mn+1);
                    string mnspace = string(" ", mn);
                    string t =  "";
                    for(int k=i;k<=j-1;k++){
                        if(mod-->0){
                            t += words[k]+mxspace;
                        }else{
                            t += words[k]+mnspace;
                        }
                    }
                    t += words[j];
                    ret.push_back(t);
                    ret.push_back(words[n-1]);
                }
                break;
            }
        }
        return ret;
    }
};

pair<vector<string>, int> getArgv(int index){
    if(index == 1){
        return {{"This", "is", "an", "example", "of", "text", "justification."}, 16};
    }else if(index == 2){
        return { {"What","must","be","acknowledgment","shall","be"}, 16};
    }else if(index == 3){
        return { {"Science","is","what","we","understand","well","enough","to","explain","to","a", "computer.","Art","is","everything","else","we","do"}, 20};
    }
    return {};
}

int main(int argc, char* argv[]){
    int option = atoi(argv[1]);
    auto argvs = getArgv(option);
    Solution s;
    auto ret = s.fullJustify(argvs.first, argvs.second);
    for(auto &i:ret)
        cout<<"|"<<i<<"|"<<endl;
    return 0;
}
