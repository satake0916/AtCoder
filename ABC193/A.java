import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int a = sc.nextInt();
		int b = sc.nextInt();
		sc.close();

		System.out.println(100 - (double)b * 100 / a);
	}
}
