import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		Map<Integer, Long> mp = new HashMap<>();
		for(int i = 0; i < n; i++){
			int t = sc.nextInt();
			mp.put(t, mp.getOrDefault(t, 0L)+1);
		}
		sc.close();

		long ans = 0;
		for(int i = -200; i <= 200; i++){
			for(int j = i+1; j <= 200; j++){
				ans += mp.getOrDefault(i, 0L) * mp.getOrDefault(j, 0L) * (i - j) * (i - j);
			}
		}

		System.out.println(ans);
	}
}
