#include <bits/stdc++.h>
using namespace std;

void setupFileIO(string fin = "data/input.txt", string fout = "data/B2_output2.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

vector<pair<int, int>> getFriends(int i, int j, int r, int c, string ansGrid[])
{
    vector<pair<int, int>> dirs({{0, -1}, {-1, 0}, {0, 1}, {1, 0}});
    vector<pair<int, int>> friends;
    for (auto dir : dirs)
    {
        int neigbR = i + dir.first;
        int neigbC = j + dir.second;
        if (neigbR < 0 || neigbR >= r || neigbC < 0 || neigbC >= c || ansGrid[neigbR][neigbC] == '#')
            continue;
        friends.push_back({neigbR, neigbC});
    }
    return friends;
}

void solve()
{
    int ntc;
    cin >> ntc;
    for (int tc = 1; tc <= ntc; tc++)
    {
        int row, col;
        cin >> row >> col;
        string grid[row], ansGrid[row];
        for (int i = 0; i < row; i++)
        {
            cin >> grid[i];
            ansGrid[i] = grid[i];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '.')
                    ansGrid[i][j] = '^';
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (ansGrid[i][j] == '#')
                    continue;
                int cr = i, cc = j;
                while (true)
                {
                    auto friends = getFriends(cr, cc, row, col, ansGrid);
                    auto numOfFriends = friends.size();
                    if (numOfFriends < 2)
                    {
                        ansGrid[cr][cc] = '#';
                    }
                    if (numOfFriends != 1)
                    {
                        break;
                    }
                    if (i < friends[0].first || (i == friends[0].first and j < friends[0].second))
                        break;

                    cr = friends[0].first;
                    cc = friends[0].second;
                }
            }
        }
        bool imposible = false;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '.' and ansGrid[i][j] == '#')
                    ansGrid[i][j] = '.';
                if (grid[i][j] == '^' and ansGrid[i][j] == '#')
                    imposible = true;
            }
        }

        if (imposible)
            cout << "Case #" << tc << ": "
                 << "Impossible"
                 << "\n";
        else
        {
            cout << "Case #" << tc << ": "
                 << "Possible"
                 << "\n";
            for (int i = 0; i < row; i++)
                cout << ansGrid[i] << "\n";
        }
    }
}

int main()
{
    setupFileIO();
    solve();
    return 0;
}