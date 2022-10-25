import java.util.*;

public class BinaryHeap {
	static ArrayList<Integer> list = new ArrayList<Integer>();

	static void swap(int x, int y){
		int z = list.get(x);
		list.set(x, list.get(y));
		list.set(y, z);
	}

	static void insert(int x){
		list.add(x);
		int i = getSize()-1;
		while(i != 0){ 
			int p = (i-1)/2;
			if(list.get(p) < list.get(i)){
				swap(p, i);
			}
			else break;
			i = p;
		}
	}

	static int getMax(){
		return list.get(0);
	}

	static void removeMax(){
		if(getSize() == 0) return;
		if(getSize() == 1) list.remove(0);
	        else if( getSize() == 2){
			swap(0, 1);
			list.remove(1);
		}else{
			int e = getSize()-1;
			swap(0, e);
			list.remove(e);
			e = 0;
			while(2*(e+1) < getSize()){
				if(list.get(2*(e+1)) < list.get(2*e+1)){
					swap(e, 2*e+1);
				}else{
					swap(e, 2*(e+1));
				}
				e = 2*(e+1);
			}
		}
	}

	static int getSize(){
		return list.size();
	}

	static void checkSize(int expected) {
 		int got = getSize();
    		if (got != expected) {
	       	 	System.out.println("Got size "+got+", expected "+expected);
    		}
	}

	static void checkMax(int expected) {
    		int got = getMax();
    		if (got != expected) {
        		System.out.println("Got max "+got+", expected "+expected);
    		}
	}
	
	public static void main(String[] args){
		checkSize(0);
    		insert(1);
    		insert(2);
    		insert(3);
    		insert(4);
    		insert(5);
		System.out.println(list);
    		checkMax(5);
    		removeMax();
		System.out.println(list);
		removeMax();
		System.out.println(list);
    		removeMax();
		System.out.println(list);
		checkSize(2);
    		checkMax(2);
	}
}

