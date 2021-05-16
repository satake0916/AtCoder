import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		sc.close();

		int ans = n / 100 + 1;
		if(n % 100 == 0) ans--;

		System.out.println(ans);
	}
}
