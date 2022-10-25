import java.util.*;

public class BirthMemorization{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);	
		int N = sc.nextInt(); sc.nextLine();
	        Person[] arr = new Person[N];
		for(int i=0; i < N; i++){
			String n = sc.next(); 
			int l = sc.nextInt(); 
			String[] s = sc.nextLine().trim().split("/");
			arr[i] = new Person(n, l, Integer.parseInt(s[0]), Integer.parseInt(s[1]));
		}
		Arrays.sort(arr, new NC());
		HashMap<String, String> ans = new HashMap<String, String>();
		ans.put(arr[0].key , arr[0].name);

	        for(int i=1; i < N; i++){
			String s = arr[i].name;
			ans.computeIfAbsent(arr[i].key, v -> s);
		}

		ArrayList<String> s = new ArrayList<String>(ans.values());
		Collections.sort(s);
		System.out.println(s.size());
		Iterator<String> it = s.iterator();
		while(it.hasNext()){
			System.out.println(it.next());
		}

	}
}


class Person {

		String name;
		int love;
		int dd;
		int mm;
		String key;
		Person(String n, int l, int d, int m){ 
			name=n; love=l; 
			dd=d; mm=m; 
			key =d+"/"+m;
		}

		public String toString(){
			return name+" "+love+" "+key;
		}
}

class NC implements Comparator<Person> {
		@Override
		public int compare(Person p1, Person p2){
			if(p1.mm != p2.mm) return p1.mm - p2.mm;
			else{
				if(p1.dd != p2.dd) return p1.dd - p2.dd;
				else return p2.love - p1.love;
			}
		}	
}



