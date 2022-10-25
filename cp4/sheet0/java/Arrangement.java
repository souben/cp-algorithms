import java.util.*;

public class Arrangement {
    
    
    static String printflag(int n){
        if(n==1) return "*";
        String sn = printflag(n/2);
        return n%2!=0 ? sn+sn+"*": sn+sn;
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); sc.nextLine();
        int m = sc.nextInt(); sc.nextLine();
        int div = m/n;
        int mod = m%n;
        for( int i=0; i < n;i++ ){
            String s = printflag(div);
            if(mod > 0){
                s+="*";
                mod--;
            }
            System.out.println(s);
	    
        }
	
        
    }
}
