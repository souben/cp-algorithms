



public class CheckNthBit {
	public static int solution(int x, int n){
		return x & (1 << n);
	}

	public static void main(String args[]){
		System.out.println(solution(2, 1)!=0);
	}
}	


