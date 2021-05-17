import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		int x = 0, y = 1001;
		for(int i = 0; i < n; i++){
			int a = sc.nextInt();
			x = Math.max(x, a);
		}
		for(int i = 0; i < n; i++){
			int b = sc.nextInt();
			y = Math.min(y, b);
		}
		sc.close();

		System.out.println(Math.max(0, y-x+1));
	}
}
