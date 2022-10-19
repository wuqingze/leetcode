class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int ret = n;
        ret += min(word[0]-'a', 'z'-word[0]+1);
        for(int i=1;i<n;i++){
            if(word[i]>word[i-1]){
                ret += min(word[i]-word[i-1], 'z'-word[i]+word[i-1]-'a'+1);
            }else{
                ret += min(word[i-1]-word[i], 'z'-word[i-1]+word[i]-'a'+1);
            }
        }
        return ret;
    }
};
