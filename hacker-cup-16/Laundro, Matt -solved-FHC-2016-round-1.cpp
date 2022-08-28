#include <bits/stdc++.h>

#define ll long long
#define mx  1000005
#define mod 1000000007
#define lim 100

using namespace std;
ll lt[mx],drier[mx];

int main() {
	freopen("laundro_matt.txt","r",stdin);
	freopen("inter.txt","w",stdout);

	ios_base ::sync_with_stdio(false);

	int t;cin>>t;

	for(int cs=1;cs<=t;cs++)
	{
		ll l,n,m,d;cin>>l>>n>>m>>d;

		priority_queue<pair<ll,ll> >pq;

		for(int i=0;i<n;i++)
		{
			int e;cin>>e;
			pq.push({-e,-e});
		}

		for(int i=1;i<=l;i++)
		{
			drier[i]=0;
			pair<ll,ll>lest=pq.top();pq.pop();
			lt[i]=-lest.first;
			pq.push({lest.first+lest.second,lest.second});

		}
             ll ans=0;

	     int j=0;
		for(int i=1;i<=l;i++)
		{
			j%=m;

                        if(drier[j+1]>lt[i])
               	           drier[j+1]=drier[j+1]+d;
                        else
               	           drier[j+1]=lt[i]+d;
			ans=max(drier[j+1],ans);
			j++;
		}

		cout<<"Case #"<<cs<<": "<<ans<<"\n";
	}
     return 0;
}
