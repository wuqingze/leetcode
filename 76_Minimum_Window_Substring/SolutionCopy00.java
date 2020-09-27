import java.util.Map;
import java.util.HashMap;

class SolutionCopy00{
    public static String minWindow(String s, String t){
        if(s.length() == 0 || t.length() == 0) return "";
        
        Map<Character, Integer> dictT = new HashMap<Character, Integer>();
        for(int i=0;i<t.length(); i++){
            int count = dictT.getOrDefault(t.charAt(i), 0);
            dictT.put(t.charAt(i), count +1);
        }

        int required = dictT.size();
        int l =0, r=0;
        int formed = 0;

        Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();

        // ans list of the form (window length, left, right)
        int[] ans = {-1, 0, 0};
        while(r<s.length()){
            char c = s.charAt(r);
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            if(dictT.containsKey(c) && windowCounts.get(c).intValue() ==
                    dictT.get(c).intValue()){
                formed += 1;
            }

            while(l<=r && formed == required){
                c = s.charAt(l);
                if( ans[0] == -1 || r-l+1 < ans[0]){
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }
                windowCounts.put(c, windowCounts.get(c) -1);
                if(dictT.containsKey(c) && windowCounts.get(c).intValue() <
                        dictT.get(c).intValue()){
                    formed --;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1?"":s.substring(ans[1], ans[2]+1);
    }

    public static void main(String[] args){
        System.out.println(SolutionCopy00.minWindow("ADOBECODEBANC", "ABC"));
        System.out.println(SolutionCopy00.minWindow("iiBAC", "ABC"));
    }
}

