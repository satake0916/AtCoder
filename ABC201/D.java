import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int h = sc.nextInt();
		int w = sc.nextInt();
		int[][] a = new int[h][w];
		for(int i = 0; i < h; i++){
			String s = sc.next();
			for(int j = 0; j < w; j++){
				if(s.charAt(j) == '+') a[i][j] = 1;
				if(s.charAt(j) == '-') a[i][j] = -1;
			}
		}
		sc.close();

		int table[][] = new int[h][w];
		table[h-1][w-1] = 0;
		for(int i = h-2; i >= 0; i--){
			if((i + w-1) % 2 == 0) table[i][w-1] = table[i+1][w-1] + a[i+1][w-1];
			else table[i][w-1] = table[i+1][w-1] - a[i+1][w-1];
		}

		for(int i = w-2; i >= 0; i--){
			if((i + h-1) % 2 == 0) table[h-1][i] = table[h-1][i+1] + a[h-1][i+1];
			else table[h-1][i] = table[h-1][i+1] - a[h-1][i+1];
		}

		for(int i = h-2; i >= 0; i--){
			for(int j = w-2; j >= 0; j--){
				if((i+j) % 2 == 0) table[i][j] = Math.max(table[i+1][j] + a[i+1][j], table[i][j+1] + a[i][j+1]);
				else table[i][j] = Math.min(table[i+1][j] - a[i+1][j], table[i][j+1] - a[i][j+1]);
			}
		}

		String ans = "Draw";
		if(table[0][0] > 0) ans = "Takahashi";
		if(table[0][0] < 0) ans = "Aoki";
		
		System.out.println(ans);
	}
}
