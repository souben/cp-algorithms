


public class LargestPower {
	public static int solution(int x) {
		if(x == 0) return 0;
		int cnt = 0;
		while(x != 0){
			x/=2;
			cnt++;
		}
		cnt--;
		return 1 << cnt;
	}

	public static void main(String args[]){
		System.out.println(solution(Integer.parseInt(args[0])));
	}
}



