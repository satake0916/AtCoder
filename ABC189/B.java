import java.util.*;

public class Main {
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] v = new int[n];
		int[] p = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++){
			v[i] = sc.nextInt();
			p[i] = sc.nextInt();
		}
		sc.close();

		for(int i = 0; i < n; i++){
			sum += v[i] * p[i];
			if(sum > x*100){
				System.out.println(i+1);
				return;
			}
		}

		System.out.println(-1);
	}
}
