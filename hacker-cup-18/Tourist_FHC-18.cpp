#include <bits/stdc++.h>

#define ll long long


using namespace std;

struct st{
	string nam;
	int id;

	bool operator<(st p)
	{
		return id<p.id;
	}
};

int main(){
	   //freopen("tourist (2).txt","r",stdin);
     //freopen("out.txt","w",stdout);

	ios_base ::sync_with_stdio(false);

     int t;cin>>t;

     for(int cs=1;cs<=t;cs++)
	{
		ll n,k,v;cin>>n>>k>>v;
		string s[n+5];
		st ans[k+5];

		for(int i=0;i<n;i++)
			cin>>s[i];

		int pos=int((k*(v-1))%n);

		int j=0;

		while(j<k)
		{
			int in=int(pos%n);
			ans[j].nam=s[in];
			ans[j].id=in;

			j++,pos++;
		}

		sort(ans,ans+k);
		cout<<"Case #"<<cs<<":";

		for(int i=0;i<k;i++)
			cout<<" "<<ans[i].nam;
		cout<<"\n";
	}
     return 0;
}
