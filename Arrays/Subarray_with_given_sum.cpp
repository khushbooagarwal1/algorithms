//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define untill(i, t) for(__typeof(t) i = 0; i < t; i++)
#define foreach(v, c) for(__typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define revforeach(v, c) for(__typeof( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define ALL(v) (v).begin(), (v).end()

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

typedef long long int lli;

const int INT_INFINITY = 1001001001;
const lli LONG_INFINITY = 1001001001001001001ll;

typedef pair<int, int> pii;
typedef pair<long, long> pll;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;


int main() {

    int T;
    cin >> T;
    for(; T > 0; T--) {
        int N, S;
        cin >> N >> S;
        vector<int> array(N);
        for(int i = 0; i < N; i++) {
            cin >> array[i];
        }
        int first = 0, last = 0;
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += array[i];
            last = i;
            while(sum > S) {
                sum -= array[first];
                first++;
                if(first > last) {
                    break;
                }
            }
            if(sum >= S){
                break;
            }
        }
        if(sum == S) {
            cout << first + 1 << " " << last + 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
	    return 0;
}
