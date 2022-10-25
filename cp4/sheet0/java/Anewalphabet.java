import java.util.*;

public class Anewalphabet {
	public static void main(String[] args){
		String[] arr = {"@", "8","(", "|)", "3", "#", "6", "[-]", "|" , "_|" , "|<" , "1" , "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z","$","']['","|_|","\\/","\\/\\/","}{","`/", "2"};
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		int i = 0;
		String ans = "";
	       	while(i < s.length()){
			char c = s.charAt(i);
			if((c >='a' && c<='z')||(c>='A' && c<='Z')){
				ans += arr[Character.toLowerCase(c)-'a'];
			}else{
				ans+= c;
			}	
			i++;
		}	
		System.out.println(ans);
		sc.close();
	}
}
