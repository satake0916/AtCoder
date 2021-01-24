import java.util.*;

public class Main {
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
		}
		sc.close();

		int ans = -1;
		for(int i = 0; i < n; i++){
			int minv = a[i];
			for(int j = i; j < n; j++){
				minv = Math.min(minv, a[j]);
				ans = Math.max(ans, minv*(j-i+1));
			}
		}

		System.out.println(ans);
	}
}
