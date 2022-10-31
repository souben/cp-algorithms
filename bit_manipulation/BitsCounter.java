



public class BitsCounter {
	public static int solution(int x){
		int c = 0;
		while(x != 0){
			x = (x&(x-1));
			c++;
		}
		return c;
	}


	public static void main(String args[]){
		System.out.println(solution(6));
	}
}
