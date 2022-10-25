import java.util.*;

public class Transitwoes {
	public static void main(String[] args){
		int s, t, n;
		Scanner sc = new Scanner(System.in);
		s = sc.nextInt();
		t = sc.nextInt();
		n = sc.nextInt();

		int[] di = new int[n+1];
		int[] bi = new int[n];
		int[] ci = new int[n];

		int i=0;
		while(i <= n){
			di[i++] = sc.nextInt();
		}
		sc.nextLine();
	
		i = 0;
		while(i < n){
			bi[i++] = sc.nextInt();
		}
		sc.nextLine();

		i = 0;
		while(i < n){
			ci[i++] = sc.nextInt();
		}
		sc.nextLine();

		int ct = s;
		for(i=0; i < n; i++){
			int c = ci[i];
			while(di[i] > ci[i]){
				ci[i]+=c;
			}
			ct+=ci[i]+bi[i];
		}

		ct += di[n];
		String ans = ct <= t ? "yes" : "no"; 
		System.out.println(ans);
		sc.close();
	}
}
