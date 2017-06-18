#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
void connectd_comp(int v, vector< bool > & visited, map< int, vector< int > > & connected, int & count)
{
    visited[v] = 1;
    count++;
 
    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    
      //check for all all people from same country
      for(i = connected[v].begin(); i != connected[v].end(); ++i){
          if(!visited[*i])
              connectd_comp(*i, visited, connected, count);
      }
}

 
int main()
{ 
    int N, I, count;
    cin >> N >> I;
    map<int, vector<int> > pairs;
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    vector< bool > visited(N, 0);
    vector< int > res;
    for (int v=0; v<N; v++)
    {
        count = 0;
        //each connected component denotes one country people
        if (visited[v] == 0)
        {
           connectd_comp(v, visited, pairs, count);
           res.push_back(count);
        }
    }
    int len = res.size();
    //can't choose people from two different country
    long long result = 0;
    if(len == 1){
        result = 0;
    }
    long long sum = 0;
    //(2, 3, 4) = (2c1 * 3c1 + 2c1 * 4c1 + 3c1 * 4c1) = (2 * 3 + 3 * 2 + 4 * 2)
    //the below code gives pairwise multiplication and then summation in O(n)
    for(int i = 0; i < len; i++){
      result += sum*long(res[i]);
      sum += long(res[i]);
    }
    cout <<  result;
    return 0;
}
