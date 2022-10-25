import java.util.*;

public class ACM {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
HashMap<String, Integer[]> map = new HashMap<String, Integer[]>();}	
		while(sc.hasNextLine())
			int ti; String pr; int ac;
			ti = sc.nextInt(); 
			if(ti == -1) break;
			pr = sc.next(); ac = sc.nextLine().trim().equals("wrong") ? 0 : 1;
			map.compute( pr , (k, v) -> {
				int t = ac == 0 ? 20 : ti;
				if(v == null){
					v = new Integer[]{ac, t};
				}else {
					v[0] = ac;
					v[1] += t;
				}
				return v;
			});
		}

		Iterator<Map.Entry<String, Integer[]>> it = map.entrySet().iterator();
		int ans = 0;
		int cnt = 0;
		while(it.hasNext()){
			Integer[] arr = it.next().getValue(); 
			if( arr[0] == 1) {
				ans+= arr[1];
				cnt+= 1;
			}
		}
		System.out.println(cnt+" "+ans);
	}
}
