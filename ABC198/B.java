import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		String s = sc.next();
		sc.close();


		boolean f = isPalindrome(fix(s));
		System.out.println(f ? "Yes" : "No");
	}

	private static String fix(String s){
		String ret = s;
		while(ret.charAt(ret.length()-1) == '0'){
			ret = ret.substring(0, ret.length()-1);
			if(ret.length() == 0) return ret;
		}
		return ret;
	}

	private static boolean isPalindrome(String s){
		boolean ret = true;
		for(int i = 0, j = s.length()-1; i <= j; i++, j--){
			if(s.charAt(i) != s.charAt(j)){
				ret = false;
				break;
			}
		}
		return ret;
	}
}
