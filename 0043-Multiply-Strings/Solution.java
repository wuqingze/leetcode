import java.util.*;
import java.io.*;

class Solution {
	public int[] plus(int[][] middleNum){
		int[] result = new int[300];
        int jinwei = 0;

		for(int j=0;j<middleNum[0].length; j++){
			int temp = 0;
			for(int i=0;i<middleNum.length; i++){
				temp += middleNum[i][j];
			}
			temp += jinwei;
			result[j] = temp % 10;
			jinwei = temp /10;
		}			
		int c = result.length-1;
		for(; c>=0; c--){
			if(result[c] != 0){
				break;
			}
		}
		if(c<0){
			return new int[]{0};
		}
		int[] result1 = new int[c+1];
		for(int i=0;i<c+1;i++){
			result1[i] = result[i];
		}
		return result1;
	}

	public Map<Character,String> oneToNine(String nums){
		int[] onenine = new int[]{0,1,2,3,4,5,6,7,8,9};
		Map<Character, String> result = new HashMap<Character, String>();
		for(int c: onenine){
		        int jinwei = 0;
			StringBuilder sb = new StringBuilder();
			for(int i=0;i<nums.length(); i++){
				int temp = c * (nums.charAt(i)-'0');
				sb.append((char) (((temp+jinwei)%10)+'0'));
				jinwei = (temp+jinwei) /10;
			}
			if(jinwei != 0){
				sb.append((char) (jinwei+'0'));
			}
			result.put((char) (c+'0'),sb.toString());
		}
		return result;
	}

	public String multiply(String num1, String num2) {
		char[] rnum1char = new char[num1.length()];
		char[] rnum2char = new char[num2.length()];
		for(int i=num1.length()-1;i>=0;i--){
			rnum1char[rnum1char.length-i-1] = num1.charAt(i);
		}
		for(int i=num2.length()-1;i>=0;i--){
			rnum2char[rnum2char.length-i-1] = num2.charAt(i);
		}
		Map<Character, String> onenine = oneToNine(new String(rnum1char));
		int[][] middleNum = new int[num2.length()][300];
		
		for(int i = 0;i<rnum2char.length;i++){
			String t = onenine.get(rnum2char[i]);
			for(int j=0;j<t.length();j++){
				middleNum[i][i+j] = t.charAt(j)-'0';
			}
		}
		int[] intresult = plus(middleNum);
		StringBuilder sb = new StringBuilder();
		for(int i=intresult.length-1;i>=0;i--){
			sb.append((char) (intresult[i]+'0'));
		}
		return sb.toString();
	}

	public static void main(String[] args){
		int[] a = new int[3];
		Solution s = new Solution();
		// System.out.println(s.multiply("123","456"));
		// System.out.println(s.multiply("2", "3"));
		// System.out.println(s.multiply("0", "235"));
		System.out.println(s.multiply("581852037460725882246068583352420736139988952640866685633288423526139","2723349969536684936041476639043426870967112972397011150925040382981287990380531232"));
	}
}
