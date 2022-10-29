#include <iostream> 
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>


using namespace std;

const int N = 1e2;
int xm[] = {1, 2, 2, 1, -1, -2, -2, -1};
int ym[] = {-2, -1, 1, 2, 2, 1, -1, -2};
char x[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char y[] = {'1', '2', '3', '4', '5', '6', '7', '8'};

int vis[N];
unordered_map<string, int> map;

int moves;
string s, t;

void bfs(int& moves){
	int bs = 8;
	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));
	while(q.size()){ 
		pair<string, int> p = q.front();
		string sq = p.first;
		q.pop();
		vis[map[sq]] = 1;
		for(int j=0; j < bs; j++){
			char xc = sq[0]+xm[j];
			char yc = sq[1]+ym[j];
			string ss(1, xc); ss.push_back(yc);
			if(!map[ss]) continue;
			if(ss == t){
				moves = p.second+1;
				return ;
			}	
			int n = p.second+1;
			if(!vis[map[ss]]) q.push(make_pair(ss, n));
		}
	}
}


int main(){
	int bs = 8;
	int idx = 1;
	for(int i=0; i < bs; i++){
		for(int j=0; j < bs; j++){
			char xc = i+(int)'a';
		        char yc = j+(int)'1';	
			if(xc >= 'a'&& xc <= 'h' && yc >= '1' && yc <='8'){
				string s;
				s.push_back(xc); s.push_back(yc);
				map[s] = idx++;

       			}
		}	
	}
        
	while(cin >> s >> t){
		//cout << s << " " << t << endl;
		moves = 0;
		if(s == t){
			cout<<"To get from e2 to e4 takes "<<moves<<" knight moves."<< endl;
			continue;
		}
		for(int i=1; i < N; i++)
			vis[i] = 0;

		bfs(moves);
		cout<<"To get from e2 to e4 takes "<<moves<<" knight moves."<< endl;
	}
}	




