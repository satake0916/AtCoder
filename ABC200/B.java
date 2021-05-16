import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		long n = sc.nextInt();
		long k = sc.nextInt();
		sc.close();

		for(int i = 0; i < k; i++){
			if(n % 200 == 0) n /= 200;
			else n = n*1000 + 200;
		}

		System.out.println(n);
	}
}
