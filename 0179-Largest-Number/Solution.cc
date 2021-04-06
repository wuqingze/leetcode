class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> l(n);
        
        for(int i=0;i<n;i++) l[i] = to_string(nums[i]);
        
        sort(l.begin(), l.end(), [](const string& s1, const string& s2){
            return s1+s2>s2+s1;
        });
        if(l[0] == "0") return "0";
        
        string ret = "";
        for(auto &s:l) ret += s;
        return ret;
    }
};
