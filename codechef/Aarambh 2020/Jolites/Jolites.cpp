#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	cin >> N;
	string pat = "JGEC";
	for(int i = 0; i < N; i++) {
		int a;
		string s;
		cin >> a;
		cout << a;
		cin >> s;
		cout << s;
		int start = s.find(pat);
		int count = 0;
		while(start != -1 && start + 4 <= s.size()){
			count++;
			start = s.find(pat, start);
		}
		if(i != 0){
			cout << endl;
		}
		cout << count;

	}
	return 1;
}
