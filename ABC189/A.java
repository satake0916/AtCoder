import java.io.PrintWriter;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws Exception{
		//入力
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();

		//処理
		String ans = (s.charAt(0) == s.charAt(1) && s.charAt(0) == s.charAt(2)) ? "Won" : "Lost";
 

		//出力
		PrintWriter out = new PrintWriter(System.out);
		out.println(ans);
		out.flush();
	}
}
