#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main(){

    // freopen("ethan_searches_for_a_string.txt","r",stdin);
	  // freopen("ans.txt","w",stdout);
	ios_base ::sync_with_stdio(false);

	int t;
	cin>>t;

	for(int cs=1;cs<=t;cs++)
	{
		string a;cin>>a;
		int l=a.size();

		int suf[l+5];

		int i=0,j=1;
		suf[i]=0;

		while(j<l)
		{
			if(a[i]==a[j])
			{
				suf[j]=i+1;
				i++,j++;
			}
			else if(i==0)
			{
				suf[j]=0;
				j++;
			}
			else
			{
				i=suf[i-1];
			}
		}

		j=0;
		for(int ii=0;ii<l-1;ii++)
		{
			if(suf[ii]>0 && suf[ii]>=suf[ii+1])
			{
				j=suf[ii],i=ii;
				break;
			}
		}

		if(j==0)
		{
			cout<<"Case #"<<cs<<": "<<"Impossible"<<"\n";
			continue;
		}
		cout<<"Case #"<<cs<<": ";

		for(int ii=0;ii<=i;ii++)
		{
			cout<<a[ii];
		}

		for(int ii=j;ii<l;ii++)
			cout<<a[ii];
		cout<<"\n";
	}
     return 0;
}
