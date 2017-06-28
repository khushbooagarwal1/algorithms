#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
	while(t--){
        int n;
        cin >> n;
        vector< string > s(n);
        for(int i = 0; i < n; i++){
            cin>>s[i];
        }
        //stores frequency of each adjacent repeating character
        vector< vector< int > > freq(100);
        //stores each adjactent repeating character(distinct character)
        vector< vector< int > > character(100);
        
        for(int i = 0; i < n; i++)
        {
            int count = 1;
            for(int j = 1; j < s[i].length(); j++)
            {
                //if current character is same as previous one, increase count
                if(s[i][j]==s[i][j-1])
                    count++;
                else
                {
                    //else insert previous character and its frequency
                    freq[i].emplace_back(count);
                    character[i].emplace_back(s[i][j-1]);
                    //reset count
                    count=1;
                }
            }
            //store last character and its frequency
            freq[i].emplace_back(count);
            character[i].emplace_back(s[i][s[i].length()-1]);
        }
        
        int flag = 0;
        
        //check if all strings has equal number of distinct characters
        int temp=freq[0].size();
        for(int i = 0; i < n; i++){
            if(freq[i].size() != temp){
                flag = 1;
                break;
            }
        }
        //if all strings has equal number of distinct characters
        if(!flag){
            //check order of distinct character is same or not
            for(int j = 0; j < temp; j++)
            {
                int cur = character[0][j];
                //for each string
                for(int i = 1; i < n; i++)
                {
                    if(character[i][j] != cur){
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
		if(flag)
            cout<<"-1\n";
        else
        {
            //all well
            int ans=0;
            for(int j = 0; j < temp; j++){
                //get frequency of each distinct character one by one
                vector< int > pos_freq;
                for(int i = 0; i < n; i++)
                {
                    pos_freq.emplace_back(freq[i][j]);
                }
                //sort in ascending order
                sort(pos_freq.begin(), pos_freq.end());
                //reduction to middle length is always cheaper for both smaller and larger frequency
                int mid = pos_freq[(n-1)/2];
                
                for(auto a:pos_freq)
				    ans += abs(mid-a);			//distance from mid frequency(either insertion or deletion)
		  }
		  cout<<ans<<"\n";
        }
	}

    return 0;
}
