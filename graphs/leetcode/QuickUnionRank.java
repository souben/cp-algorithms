public class QuickUnionRank {
	private int[] dsu;
	private int[] rank;

	public QuickUnionRank(int size){
		this.dsu = new int[size];
		this.rank = new int[size];
		this.init();
	}

	public void init(){
		for(int i=0 ; i< dsu.length; i++ ){
			this.dsu[i] = i;
			this.rank[i] = 1;
		}
	}

	public int[] getRootArray(){
		return this.dsu;
	}

	public int find(int x){
		while(dsu[x] != x){
			x = dsu[x];
		}
		return x;
	}

	public void union(int x, int y){
		int rootX = find(x);
	       	int rootY = find(y);
		if( rootX != rootY ){
			if(rank[rootX] > rank[rootY])
				dsu[rootY] = rootX;
			else if(rank[rootX] < rank[rootY])
				dsu[rootX] = rootY;
			else
				dsu[rootY] = rootX;
				rank[rootX]+=1;
		}
	}

	public static void main(String[] args){
		QuickUnionRank dsu = new QuickUnionRank(8);
		dsu.union(0, 1);
		dsu.union(0, 2);
		dsu.union(0, 3);
		dsu.union(0, 4);
		int[] root = dsu.getRootArray();
		
		for(int i=0; i < root.length; i++ ){
			System.out.print(root[i]+" ");
		}

		System.out.println('\n');
		dsu.union(6, 5);
		dsu.union(7, 5);
		
		for(int i=0; i < root.length; i++ ){
			System.out.print(root[i]+" ");
		}

		System.out.println('\n');
	}
}
