#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

//convert string to lowercase
void lower(string& s){
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'Z' + 'z';
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    map< string, vector< string > > adj;
    for(int i = 0; i < n; i++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        lower(s1);
        lower(s3);
        adj[s3].push_back(s1);
    }
    queue< pair< string, int > > q;     //using bfs algorithm
    int max = 1;    //to store maximum food chain length
    q.push(make_pair("cheese", 1));   //initial food and length of food chain
    while(!q.empty()){
        string src = q.front().first;
        int temp = q.front().second + 1;
        vector< string>::iterator it;
        
        //check all adjacent consumer
        for(it = adj[src].begin(); it != adj[src].end(); it++){
            q.push(make_pair(*it, temp));
            if(temp > max){
                max = temp;
            }
        }
        q.pop();
    }
    cout << max;
    return 0;
}
