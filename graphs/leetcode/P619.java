import java.util.*;



public class P619 {
	private static int[][] edges;
	private static Stack<Integer> stack;
	private static ArrayList<Integer>[] adj_list;
	private static boolean[] visited;
	private static int src;
	private static int dest;
	
	public static boolean dfs(){
		stack.push(src);
		while(!stack.empty()){
			int a = stack.pop();
			System.out.println(a+" "+dest);	
			visited[a] = true;
			for(int i=0; i < adj_list[a].size(); i++){
				int j = adj_list[a].get(i);
				if(j == dest) return true;
				if(visited[j]) continue;
				stack.push(j);
			}
		}
		return false;
	}



	public static boolean validPath(int n, int[][] edges, int source, int dest){
		edges = edges;
		src = source;
		dest = dest;
		stack  = new Stack<Integer>();
		visited = new boolean[n];
		adj_list = new ArrayList[n];
		for(int i=0; i < edges.length; i++){
			int[] e = edges[i];
			if(adj_list[e[0]] == null){
				adj_list[e[0]] = new ArrayList<Integer>();
			}
			if(adj_list[e[1]] == null){
				adj_list[e[1]] = new ArrayList<Integer>();
			}
			adj_list[e[0]].add(e[1]);
			adj_list[e[1]].add(e[0]);
		}
		
		return dfs();
	}

	public static void main(String[] args){
		int n = 3;
		int[][] edges = {new int[]{0,1}, new int[]{1,2}, new int[]{2, 0}};
		int source = 0;
		int dest = 2;
		boolean v = validPath(n, edges, source, dest);
		System.out.println(v);
	}
}
