#include <bits/stdc++.h>
using namespace std;
int ans = 100;
void dfs(int n, int m, int** input, int s_x, int s_y, int dist){
	//cout << s_x << s_y << endl;
	if(input[s_x][s_y] == -3){
		ans = min(ans, dist);
		if(ans == 0){
			flag = 1;
		}
		if(s_x != m-1 && ans == 1){
			flag = 1;
		}
		return;
	}
	else{
		input[s_x][s_y] = dist;
	}
	for(int i = 0; i < s_y && input[s_x][i] != 0; i++){
	//	cout << input[s_x][i];
		if(input[s_x][i] < 0 || input[s_x][s_y] < input[s_x][i]){
			dist = input[s_x][s_y];
		//	cout << "here" << endl;
			dfs(n, m, input, s_x, i, dist);
		}
		else{
			break;
		}
	}
	for(int i = s_y+1; i < m && input[s_x][i] != 0; i++){
		if(input[s_x][i] < 0 || input[s_x][s_y] < input[s_x][i]){
			dist = input[s_x][s_y];
			dfs(n, m, input, s_x, i, dist);
		}
		else{
			break;
		}
	}
	int last = s_x;
	for(int i = s_x + 1; i < n; i++){
		if(input[i][s_y] != 0){
			if(input[i][s_y] < 0 || input[s_x][s_y] < input[i][s_x]){
				dist = max(input[s_x][s_y], i-last);
				last = i;
				dfs(n, m, input, i,s_y, dist);
			}
			else if(input[i][s_y] > 0){
				break;
			}
		}
	}
	for(int i = s_x - 1; i >= 0; i--){
		if(input[i][s_y] != 0){
			if(input[i][s_y] < 0 || input[s_x][s_y] < input[i][s_x]){
				dist = max(input[s_x][s_y], last-i);
				last = i;
				dfs(n, m, input, i, s_y, dist);
			}
			else if(input[i][s_y] > 0){
				break;
			}
		}
	}
}
int main(){

	int n, m;
	cin >> n >> m;
	int** input = new int*[n];
	for(int i = 0; i < n; i++){
		input[i] = new int[m];
		for(int j = 0; j < m; j++){
			cin >> input[i][j];
		}
	}
	dfs(n,m, input,n-1, 0, 0);
	cout << ans;
}
