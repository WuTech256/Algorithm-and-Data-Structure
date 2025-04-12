#include<bits/stdc++.h>
using namespace std;
#define inf 100000005
int di[4]={-1, 0, 1, 0};
int dj[4]={0, 1, 0, -1};
int main()
{
    int n, m; 
    cin>> n >> m;
    vector<vector<int>> grid(n, vector<int>(m,0));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
    {
        string s; 
        cin>>s;
        for(int j=0; j<m; j++)
        {
            if(s[j]=='x')
            {
                q.push({i,j});
                grid[i][j]=0;
            }
            else if(s[j]=='o')
            {
                grid[i][j]=-1;
            }
            else
            {
                grid[i][j]=inf;
            }
        }
    }
    int ans = -1;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int i = cur.first;
        int j = cur.second;
        for(int k = 0; k<4; k++)
        {
            int i1 = i+di[k];
            int j1 = j+dj[k];
            if(i1>=0 && i1<n && j1>=0 && j1<m && grid[i1][j1]!=0 && grid[i1][j1]!=-1)
            {
                if(grid[i][j]+1<grid[i1][j1])
                {
                    grid[i1][j1]=grid[i][j]+1;
                    q.push({i1, j1});
                }
            }
        }
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({grid[0][0],{0, 0}});
    vector<int> path;
    vector<vector<int>> used(n, vector<int>(m, 0));
    used[0][0]=1;
    // path.push_back(grid[0][0]);
    // path.push_back(grid[n-1][m-1]);
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        int i = cur.first;
        int j = cur.second;
        path.push_back(dis);
        if(i==n-1&&j==m-1)
        {
            break;
        }
        for(int k = 0; k<4; k++)
        {
            int i1 = i+di[k];
            int j1 = j+dj[k];
            if(i1>=0 && i1<n && j1>=0 && j1<m && grid[i1][j1]!=0 && grid[i1][j1]!=-1 && used[i1][j1]==0)
            {
                used[i1][j1]=1;
                pq.push({grid[i1][j1], make_pair(i1,j1)});
            }
        }
    }
    if(!path.empty())
    {
        ans = *min_element(path.begin(), path.end());
    }
    cout<<ans;
}
