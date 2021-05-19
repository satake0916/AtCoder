import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		long n = sc.nextLong();
		sc.close();

		Set<Long> st = new HashSet<>();
		for(long i = 2; i * i <= n; i++){
			long x = i*i;
			while(x <= n){
				st.add(x);
				x *= i;
			}
		}

		System.out.println(n - st.size());
	}
}
