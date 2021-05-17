import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);	
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
			a[i] %= 200;
		}
		sc.close();

		List<List<Integer>> list = new ArrayList<>();
		for(int i = 0; i < 200; i++){
			list.add(new ArrayList<Integer>());
		}

		int count = Math.min(8, n);
		for(int i = 0; i < (1<<count); i++){
			int temp = 0;
			List<Integer> tlist = new ArrayList<>();
			for(int j = 0; j < count; j++){
				if((i & (1 << j)) != 0){
					tlist.add(j+1);
					temp += a[j];
					temp %= 200;
				}
			}
			if(!list.get(temp).isEmpty()){
				System.out.println("Yes");
				output(list.get(temp));
				output(tlist);
				return;
			}else{
				list.set(temp, tlist);
			}
		}

		System.out.println("No");
	}

	private static void output(List<Integer> list){
		System.out.print(list.size());
		for(int i = 0; i < list.size(); i++){
			System.out.print(" " + list.get(i));
		}
		System.out.println();
	}
}
