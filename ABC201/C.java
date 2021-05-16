import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		String s = sc.next();
		sc.close();

		int ans = 0;

		for(int i = 0; i < 10000; i++){
			boolean[] f = new boolean[10];
			for(int a = 0; a < 10; a++) f[a] = false;

			if(i < 1000) f[0] = true;

			int temp = i;
			while(temp != 0){
				f[temp%10] = true;
				temp /= 10;
			}

			if(isOK(s,f)) ans++;
		}
		
		System.out.println(ans);
	}

	private static boolean isOK(String s, boolean[] f){
		for(int i = 0; i < 10; i++){
			if(s.charAt(i) == 'o' && f[i] == false) return false;
			if(s.charAt(i) == 'x' && f[i] == true) return false;
		}
		return true;
	}
}
