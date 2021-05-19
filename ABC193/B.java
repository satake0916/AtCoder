import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();

		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			int p = sc.nextInt();
			int x = sc.nextInt();
			if(x > a) ans = Math.min(ans, p);
		}
		sc.close();

		System.out.println((ans == Integer.MAX_VALUE) ? -1 : ans);
	}
}
