import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++) a[i] = sc.nextInt();
		sc.close();

		long ans = 0;
		int nums[] = new int[200];
		for(int i = 0; i < 200; i++) nums[i] = 0;

		for(int i = 0; i < n; i++){
			ans += nums[a[i]%200];
			nums[a[i]%200]++;
		}

		System.out.println(ans);
	}
}
