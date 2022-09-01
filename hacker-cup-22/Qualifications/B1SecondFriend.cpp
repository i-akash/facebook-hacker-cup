#include <bits/stdc++.h>

#define mx 10000
#define mod 1000000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/second_friend_input.txt", string fout = "data/B1_output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int row, col;
        cin >> row >> col;

        string grid[row];
        for (int i = 0; i < row; i++)
        {
            cin >> grid[i];
        }

        bool hasAnyTree = false;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '^')
                    hasAnyTree = true;
            }
        }

        if (hasAnyTree == false)
        {
            cout << "Case #" << tc << ": "
                 << "Possible"
                 << "\n";

            for (int i = 0; i < row; i++)
                cout << grid[i] << "\n";

            continue;
        }

        if (row < 2 || col < 2)
        {
            cout << "Case #" << tc << ": "
                 << "Impossible"
                 << "\n";
        }
        else
        {
            cout << "Case #" << tc << ": "
                 << "Possible"
                 << "\n";

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << '^';
                }
                cout << "\n";
            }
        }
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}