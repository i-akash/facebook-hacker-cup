#include <bits/stdc++.h>

#define ll long long
#define mx  105
#define mod 1000000007
#define lim 1000000000

using namespace std;
ll dp[5005][105][3],g[105][105];

int main(){

	freopen("manic_moving (1).txt","r",stdin);
	freopen("inter.txt","w",stdout);
    ios_base ::sync_with_stdio(false);

    int t;cin>>t;

    for(int cs=1;cs<=t;cs++)
    {
    	   int n,m,k;cin>>n>>m>>k;
	   int s[k+5],d[k+5];

	   for(int i=0;i<=n;i++)
         {
         	  for(int j=0;j<=n;j++)g[i][j]=lim;
         }

        for(int i=0;i<m;i++)
	   {
	   	  int a,b;ll c;cin>>a>>b>>c;

	   	  g[a][b]=min(g[a][b],c);
	   	  g[b][a]=min(g[b][a],c);
	   }

	   for(int i=0;i<k;i++)
	   	  cin>>s[i]>>d[i];


	   for(int k=1;k<=n;k++)
	   {
	   	  for(int i=1;i<=n;i++)
		  {
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					g[i][j]=0;
					continue;
				}
				if(g[i][j]>g[i][k]+g[k][j])
				{
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		  }
	   }

	   for(int i=0;i<=k;i++)
	   {
	   	for(int j=0;j<=n;j++)
	   		dp[i][j][0]=dp[i][j][1]=lim;
	   }

	   dp[0][1][0]=0;

	   for(int i=0;i<k;i++)
	   {
	   	  for(int j=1;j<=n;j++)
		  {
		  	 ll cc=g[j][s[i]]+g[s[i]][d[i]];

		  	 dp[i+1][d[i]][0]=min(dp[i+1][d[i]][0],cc+dp[i][j][0]);
		  	 cc=g[j][s[i]];
		  	 dp[i+1][s[i]][1]=min(dp[i+1][s[i]][1],cc+dp[i][j][0]);

		  	 if(dp[i][j][1]!=lim && i>0)
			 {
			 	int sor=s[i-1],de=d[i-1];

			 	cc=g[j][s[i]]+g[s[i]][de];

			 	dp[i+1][de][1]=min(dp[i+1][de][1],dp[i][j][1]+cc);

			 	cc=g[j][s[i]]+g[s[i]][de]+g[de][d[i]];

			 	dp[i+1][d[i]][0]=min(dp[i+1][d[i]][0],dp[i][j][1]+cc);
			 }
		  }
	   }

	   if(dp[k][d[k-1]][0]!=lim)
	   	cout<<"Case #"<<cs<<": "<<dp[k][d[k-1]][0]<<"\n";
	   else
	   	 cout<<"Case #"<<cs<<": "<<"-1\n";
    }

    return 0;
}
