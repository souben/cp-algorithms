import java.util.*;

public class Basketballoneonone {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int sa = 0;
		int sb = 0;
		for(int i=0; i < s.length(); i+=2){
			int p = Integer.parseInt(Character.toString(s.charAt(i+1)));
			if(s.charAt(i)=='A') sa+=p;
			else sb+=p;
		}
		char winner = sa > sb ? 'A': 'B'; 
		System.out.println(winner);
	
	}
}
