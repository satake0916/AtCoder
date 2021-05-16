import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();

		Integer[] nums = new Integer[n];
		Map<Integer, String> mp = new TreeMap<>();

		for(int i = 0; i < n; i++){
			String name = sc.next();
			int value = sc.nextInt();

			nums[i] = value;
			mp.put(value, name);
		}
		sc.close();

		Arrays.sort(nums, Collections.reverseOrder());

		System.out.println(mp.get(nums[1]));
	}
}
