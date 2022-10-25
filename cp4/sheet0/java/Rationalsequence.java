import java.util.*;

public class Rationalsequence {
	public static void findPath(int n, int d, ArrayList<String> res){
		if( n == d) return;
		else if(n > d){
			res.add("R");
			findPath(n-d, d, res);
		}else{
			res.add("L");
			findPath(n, d-n, res);
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=1; i <= n; i++){
			int l = sc.nextInt();
			String[] s = sc.nextLine().trim().split("/");
		       	int num = Integer.parseInt(s[0]);
			int den = Integer.parseInt(s[1]);
			ArrayList<String> res = new ArrayList<String>();
			findPath(num, den, res);
			Collections.reverse(res);
			int j = 1;
			for(int k=0; k < res.size(); k++){
				j*=2;
				if(res.get(k)=="R") j++;	
			}			
			System.out.println(i+" "+j);
		}
	}
}
