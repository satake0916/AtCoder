import java.io.PrintWriter;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		//入力
		int n = sc.nextInt();
		long[] a = new long[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextLong();
		}
		sc.close();

		//処理
		long ans = -1;
		for(int pat = 0; pat < 2; pat++){
			long sum = 0;
			long temp = 0;
			for(int i = 0; i < n; i++){
				sum += a[i];
				if(i % 2 == pat){
					if(sum <= 0){
						temp += Math.abs(sum) + 1;
						sum = 1;
					}
				}else{
					if(sum >= 0){
						temp += Math.abs(sum) + 1;
						sum = -1;
					}
				}
			}

			if(ans == -1){
				ans = temp;
			}else{
				ans = Math.min(ans, temp);
			}
		}

		//出力	
		out.println(ans);
		out.flush();
	}

	static class Pair{
		int w,v;
		public Pair(int a, int b){
			this.w = a;
			this.v = b;
		}
	}
}
