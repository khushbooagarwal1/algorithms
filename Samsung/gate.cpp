#include <iostream>
using namespace std;
int pos[50], people[50];
bool* filled;
int minDis;

void fillPerson(int n, string perm, int i, int person, int l, int r, int tillNow){
	if(i >= 3){
		minDis = min(minDis, tillNow);
		return;
	}
	else{
		if(tillNow > minDis){
			return;
		}
		if(person == people[perm[i] - '0']){
			fillPerson(n, perm, i+1, 0, pos[(int)perm[i+1] - '0'], pos[(int)perm[i+1] - '0'], tillNow);
		}
		else{
			while(l >= 0 && filled[l]){
				l--;
			}
			while(r < n && filled[r]){
				r++;
			}
			if(l >= 0){
				filled[l] = 1;
				fillPerson(n, perm, i, person+1, l, r, tillNow+pos[(int)(perm[i]-'0')]-l+1);
				filled[l] = 0;
			}
			if(l!= r && r < n){
				filled[r] = 1;
				fillPerson(n, perm, i, person+1, l, r, r + tillNow - pos[(int)(perm[i]-'0')]+1);
				filled[r] = 0;
			}
		}
	}


}			
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 3; i++){
		cin >> pos[i] >> people[i];
		pos[i]--;
	}
	filled = new bool[n];
	for(int i = 0; i < n; i++){
		filled[i] = 0;
	}
	string perm[6];
	perm[0] = "012";
	perm[1] = "021";
	perm[2] = "102";
	perm[3] = "120";
	perm[4] = "201";
	perm[5] = "210";
	minDis = (1<<16)-1;
	for(int i = 0; i < 6; i++){
		fillPerson(n, perm[i], 0, 0, pos[(int)(perm[i][0]-'0')], pos[(int)(perm[i][0]-'0')], 0);
	}
	cout << minDis <<endl;
	
	return 0;
}
