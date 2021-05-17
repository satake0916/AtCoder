import java.util.*;

import javax.print.attribute.standard.Fidelity;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		char array[] = sc.next().toCharArray();
		int q = sc.nextInt();
		int tabs[][] = new int[q][3];
		for(int i = 0; i < q; i++){
			tabs[i][0] = sc.nextInt();
			tabs[i][1] = sc.nextInt();
			tabs[i][2] = sc.nextInt();
		}
		sc.close();

		String ans = solve(n, array, q, tabs);

		System.out.println(ans);
	}

	private static int flipIndex(int n, int index){
		if(index <= n){
			return n + index;
		}else{
			return index - n;
		}
	}

	private static String solve(int n, char[] ca, int q, int[][] tabs){
		boolean flipped = false;
		for(int i = 0; i < q; i++){
			int t = tabs[i][0];
			int a = tabs[i][1];
			int b = tabs[i][2];

			if(t == 2){
				flipped = !flipped;
			}else{
				if(flipped){
					a = flipIndex(n, a);
					b = flipIndex(n, b);
				}
				char c = ca[a-1];
				ca[a-1] = ca[b-1];
				ca[b-1] = c;
			}
		}

		if(flipped){
			for(int i = 0; i < n; i++){
				char c = ca[i];
				ca[i] = ca[i+n];
				ca[i+n] = c;
			}
		}

		return new String(ca);
	}
}
