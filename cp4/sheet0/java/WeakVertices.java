import java.util.*;

public class WeakVertices {
	static int matrix[][];
	static int strong[];

	public static void testCase(int n, Scanner sc){	
		matrix = new int[n][n];
	        strong = new int[n];	
	
		for(int i=0; i < n ; i++ ){
			for(int j=0; j < n; j++){
				matrix[i][j] = sc.nextInt();
			}
			sc.nextLine();
		}
	
		for(int i=0; i < n ; i++ ){
			for(int j=0; j < n; j++){
				if(matrix[i][j] == 0) continue;
				for(int k=0; k < n; k++){
					if(matrix[i][k]==1 && matrix[k][j]==1){
						strong[i] = strong[j] = strong[k] = 1;
					}
				}
			}
		}	
	
		boolean b = false;
		for(int i=0 ; i < n; i++){
			if(strong[i] == 0){
				if(b) System.out.print(" "+i);
				else{
					System.out.print(i);
					b = true;
				}
			}
		}
		System.out.println();

	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt(); sc.nextLine();
			if(n != -1){
				testCase(n, sc);
			}
			else break;
		}

		sc.close();
	}
}
