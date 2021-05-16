import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		sc.close();

		int[] nums = {a, b, c};

		Arrays.sort(nums);

		String ans = "No";
		if(nums[1] - nums[0] == nums[2] - nums[1]) ans = "Yes";

		System.out.println(ans);
	}
}
