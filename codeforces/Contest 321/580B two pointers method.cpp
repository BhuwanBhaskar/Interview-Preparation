#include <sstream>
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <ctype.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define rep(i,v) for(int i=0; i<sz(v); i++)
#define clr(v, d) memset(v, d, sizeof(v))


using namespace std;

typedef vector<long long> vi;
typedef vector<string> vs;
typedef vector< vector<int> > vii;
typedef vector<long long> vll;
typedef vector< pair<long long, long long> > vpll;
typedef vector< pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int MAX = (int)1e5+5;

int main(){

    int n, d;


    while(cin>>n>>d){

        vpii x(n);
        for(int i=0; i<n; i++)
            cin>>x[i].F>>x[i].S;

        sort(all(x));

        ll res = 0, sum = 0, diff = 0, st = 0;


        for(int i=0; i<n; i++){

            diff = x[i].F - x[st].F;
			cout<<diff<<endl;
            while(diff>=d){
                sum -= x[st].S;
                diff = x[i].F - x[++st].F;
                cout<<" removing : "<<x[st].S<<" bef st : "<<st<<" diff : "<<x[++st].F<<" af st: "<<st<<endl;
            }
			cout<<" st : "<<st<<" sum : "<<sum<<" res: "<<res<<endl;
            sum += x[i].S;

            res = max(res, sum);
        }

        cout<<res<<"\n";
    }


    return 0;
}
