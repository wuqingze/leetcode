import java.util.logging.*; import java.util.*; 
public class Solution{
	static Logger logger = Logger.getLogger(Solution.class.getName());

	static{
		try{
			FileHandler fh = new FileHandler("1.log");
			fh.setFormatter(new SimpleFormatter());
			logger.addHandler(fh);
		}catch (Exception e){
		}
	}

	public int longestValidParentheses(String s) {
	    int maxans = 0;
	    Stack<Integer> stack = new Stack<>();
	    stack.push(-1);
	    for (int i = 0; i < s.length(); i++) {
	       if (s.charAt(i) == '(') {
		  logger.info(String.format("s.charat %d is %s",i,""+s.charAt(i)));
	          stack.push(i);
	       } else {
	            int pop = stack.pop();
		    logger.info(String.format("the stack pop is %d",pop));

	            if (stack.empty()) {
			logger.info(String.format("the stack is empty i is %d",i));
	                stack.push(i);
	            } else {
			int peek = stack.peek();
	                maxans = Math.max(maxans, i - peek);
			logger.info(String.format("i is %d, maxans is %d, stack.peek() is %d",i,maxans,peek));
	            }
	      }
	   }
	   return maxans;
	}

	public static void main(String[] args){

		Solution o = new Solution();
		String s = ")()())";
                int maxans = o.longestValidParentheses(s); 
                System.out.println(maxans);	
       }
}
