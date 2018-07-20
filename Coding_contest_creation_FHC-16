#include <bits/stdc++.h>

#define ll long long
#define mx  200005
#define mod 1000000007
#define lim 100

using namespace std;


int main() {
	freopen("coding_contest_creation.txt","r",stdin);
	freopen("inter.txt","w",stdout);
	ios_base ::sync_with_stdio(false);

     int t;cin>>t;

     for(int cs=1;cs<=t;cs++)
	{
		int n;cin>>n;

          stack<int>st;
		for(int i=0;i<n;i++)
		    {
		    	  int e;cin>>e;
		    	  st.push(e);
		    }

		int ans=0,in=1;
		int last=st.top();st.pop();

		while(!st.empty())
		{
			int pl=st.top();st.pop();

			if(in==4)
			{
				last=pl;
				in=1;
			}
			else if(pl>=last)
			{
				ans+=(4-in);last=pl;
				in=1;
			}
			else if(last-pl>10)
			{
				while(in<4 && last-pl>10)
				{
					last=last-10;
					in++;ans++;
				}

				if(in==4)
				{
					in=1;
					last=pl;
				}
				else
				{
					st.push(pl);
				}
			}
			else
			{
				in++;
				last=pl;
			}

		}

		ans+=(4-in);
          cout<<"Case #"<<cs<<": "<<ans<<"\n";

	}
	return 0;
}
