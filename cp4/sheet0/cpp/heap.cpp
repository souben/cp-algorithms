#include "heap.h"
#include <vector>
#include <stdexcept>

using namespace std;

vector<int > v;

void print(){
	for(auto a: v){
		cout << a << " ";
	}
	cout << endl;
}

void swap(int x, int y){
	int z = v.at(x);
	v.at(x) = v.at(y);
	v.at(y)= z;
}

int getMax(){
	if(!getSize()) throw runtime_error("Error: heap is empty.");
    	return v.at(0);
}

int getSize(){
    	return v.size();
}

void insert(int x){
	v.push_back(x);
	int i = getSize()-1;
	while(i != 0){ 
		int p = (i-1)/2;
		if(v.at(p) < v.at(i)){
			swap(p, i);
		}
		else break;
		i = p;
	}
}

void removeMax(){
	if(getSize() == 0) return;
        if(getSize() == 1) v.pop_back();
        else if( getSize() == 2){
              swap(0, 1);
              v.pop_back();
        }else{
              int e = getSize()-1;
              swap(0, e);
              v.pop_back();
              e = 0;
              while(2*(e+1) < getSize()){
                    if(v.at(2*(e+1)) < v.at(2*e+1)){
                         swap(e, 2*e+1);
                    }else{
                         swap(e, 2*(e+1));
                    }
                         e = 2*(e+1);
                    }
              }

}
