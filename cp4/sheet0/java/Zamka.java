import java.util.*;

public class Zamka {

	public static int sumDigits(int a){
		int sum = 0;
		while(a != 0){
			sum += a%10;
		        a/=10;	
		}	
		return sum;
	}

	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		int l=sc.nextInt(), d=sc.nextInt(), x=sc.nextInt();
		int i=l;
		int j=d;
		int n = 0;
		int m = 0;
		while(i<=d && j>=l){
			int nr = sumDigits(i);
			int mr = sumDigits(j);
			if(n == 0 && nr == x) n=i;
			if(m == 0 && mr == x) m=j;
			if(n != 0 && m != 0) break;
			i++;
			j--;	
		}
		System.out.println(n+"\n"+m);
	}
}
