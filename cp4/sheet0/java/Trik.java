import java.util.*;

public class Trik {
	public static void main(String[] args){
		String s;
		Scanner sc = new Scanner(System.in);
		s = sc.nextLine();
		int pos = 1;
		for(int i = 0; i < s.length(); i++ ){
			char c = s.charAt(i);
			switch(c){
				case 'A':
					if(pos == 2){pos-=1; break;};
					if(pos == 1){pos+=1; break;};
					break;
				case 'B':
					if(pos == 2){pos+=1; break;};
					if(pos == 3){pos-=1; break;};
					break;
				case 'C':
					if(pos == 3){pos-=2; break;};
					if(pos == 1){pos+=2; break;};
					break;
				default:
					pos+=0;
			}
		}
		System.out.println(pos);
		sc.close();
	}
}
