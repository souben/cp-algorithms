


public class PowerOfTwo {

	// O(log N)
	public static int solution( int x ){
		if(x == 0) return 0;
		while(x%2==0) x/=2;
		return x==1 ? 1 : 0;
	}

	// O(1)
	public static boolean sol(int x){	
		return x!=0 && x-1!=0 && (x&(x-1))==0;
	}

	public static void main(String[] args){
		System.out.println(sol(1));
	        System.out.println(sol(2));
	        System.out.println(sol(3));
	        System.out.println(sol(4));
	        System.out.println(sol(5));
	        System.out.println(sol(6));
	}
}
