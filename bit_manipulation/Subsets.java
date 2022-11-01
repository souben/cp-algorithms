



public class Subsets {
	public static void solution(char[] set){
		int n = (int) Math.pow(2, set.length);
		for(int i=0; i < n; i++){
			System.out.printf("set #%d : { ", i);
			for(int j=0; j < set.length; j++){
				if((i&(1<<j)) !=0)
					System.out.printf("%c ", set[j]);
			}
			System.out.println(" }");
		}
	}
	
	public static void main(String args[]) {
		char c[] = {'a', 'b', 'c', 'd', 'e'};
		solution(c);
	}
}




