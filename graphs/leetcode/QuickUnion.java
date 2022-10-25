

public class QuickUnion {
	private int[] root;

	public QuickUnion(int size){
		this.root = new int[size];
		for(int i = 0; i < size; i++){
		       this.root[i] = i;
		}
	}

	public int[] getRootArray(){
		return this.root;
	}

	public int find(int x){
		while(this.root[x] != x){
			x = this.root[x];
		}
		return x;
	}

	public void union(int x, int y){
		int rootX = find(x);
		int rootY = find(y);
		if( rootX != rootY ){
			this.root[rootX] = rootY;
		}
	}

	public boolean connected(int x, int y){
		return find(x) == find(y);
	}

	public static void main(String[] args){
		QuickUnion dsu = new QuickUnion(7);
		dsu.union(3, 1);
		dsu.union(4, 1);
		dsu.union(5, 2);
		dsu.union(6, 2);
		int[] root = dsu.getRootArray();
		
		for(int i=0; i < root.length; i++ ){
			System.out.print(root[i]+" ");
		}

		System.out.println('\n');
		dsu.union(1,0);
		dsu.union(0,2);
		
		for(int i=0; i < root.length; i++ ){
			System.out.print(root[i]+" ");
		}

		System.out.println('\n');
	}
}
