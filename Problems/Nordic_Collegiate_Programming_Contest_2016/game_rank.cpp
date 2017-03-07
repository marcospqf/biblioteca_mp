#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define sc3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define scs(a) scanf("%s", a)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector< vii> vvii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9 + 9;
int mapa[26];
int main()
{
	int rank=25,star=0;
	string s;
	cin>>s;
	mapa[0]=INF;
	for(int i=1;i<=10;i++) mapa[i]=5;
	for(int i=11;i<=15;i++) mapa[i]=4;
	for(int i=16;i<=20;i++) mapa[i]=3;
	for(int i=21;i<=25;i++) mapa[i]=2;
	int consec=0;
	for(char c: s){
		if(rank==0) {
			break;
		}
		if(c=='W'){
			consec++;
			star++;
			if(consec>=3 and rank>=6) star++;
			while(star>mapa[rank]){
				star-=mapa[rank];
				rank--;
				if(rank==0) break;
			}
		}
		else{
			if(rank<=20)
				star--;
			if(star<0 and rank<20){
				rank++;
				star=mapa[rank]-1;
			}
			star=max((int)0,star);
			consec=0;
		}
	}
	if(rank>0) cout<<rank<<endl;
	else{
		cout<<"Legend"<<endl;
	}
	return 0;
}
