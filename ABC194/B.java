import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		int values[][] = new int[2][n];
		for(int i = 0; i < n; i++){
			values[0][i] = sc.nextInt();
			values[1][i] = sc.nextInt();
		}
		sc.close();

		int ans = 100001;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) ans = Math.min(ans, values[0][i] + values[1][j]);
				else ans = Math.min(ans, Math.max(values[0][i], values[1][j]));
			}
		}

		System.out.println(ans);
	}
}
