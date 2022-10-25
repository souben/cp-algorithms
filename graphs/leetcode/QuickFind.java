import java.util.List;
import java.util.ArrayList;

public class UnionFind {
	private List<Integer> root;

	public UnionFind(int size){
		this.root = new ArrayList<Integer>();
		for(int i = 0; i < size; i++){
		       this.root.add(i);
		}
	}

	public List<Integer> getRootArray(){
		return this.root;
	}

	public int find(int x){
		return this.root.get(x);
	}

	public void union(int x, int y){
		int rootX = find(x);
		int rootY = find(y);
		if( rootX != rootY ){
			for(int i=0; i< this.root.size(); i++){
				if( this.root.get(i) == rootY )
					root.set(i, rootX);
			}
		}
	}

	public boolean connected(int x, int y){
		return find(x) == find(y);
	}


	public static void main(String[] args){
		UnionFind dsu = new UnionFind(7);
		dsu.union(3, 1);
		dsu.union(4, 1);
		dsu.union(5, 2);
		dsu.union(6, 2);
		List<Integer> root = dsu.getRootArray();
		for(int i=0; i < root.size(); i++ ){
			System.out.print(root.get(i)+" ");
		}
		System.out.println('\n');
		dsu.union(1,0);
		dsu.union(0,2);
		for(int i=0; i < root.size(); i++ ){
			System.out.print(root.get(i)+" ");
		}
		System.out.println('\n');
	}
}
