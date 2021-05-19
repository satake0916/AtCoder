import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();

		int ans = 4;

		if(a+b>=15 && b>=8) ans = 1;
		else if(a+b>=10 && b>=3) ans = 2;
		else if(a+b>=3) ans = 3;

		System.out.println(ans);
	}
}
