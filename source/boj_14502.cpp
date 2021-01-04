#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
1. 풀이 과정

1) 시간복잡도를 계산합니다.
- '어디에 3개의 벽을 세워야 가장 안전할까'에 대한 로직을 구하여 완전 탐색을 하지 않아도 되지만 
시간복잡도가 여유롭다면 3개의 벽을 세우는 모든 경우를 계산할 수 있습니다.
- 64개의 노드에서 3개를 고르므로 64C3이고 , 그 경우마다 BFS를 돌려 완전탐색을 해야 합니다.

2) 64C3을 구합니다.
- 백준님의 N과M문제에서 NCM(조합)을 배웁니다.
- 조합의 경우 DFS와 탐색과정을 배열에 저장하여 계산합니다.
- 이 과정에서 64개의 노드가 pair 구조이므로 계산에 편리함을 위해 어차피 index로 생각하면 0부터 시작하는
자연수 이므로 pair의 tmp 대신에 str의 v를 사용하여 관리했습니다.

3) BFS
- 위에서 구한 모든 경우에 대해서 BFS를 사용합니다. 
- 모든 경우에 대해 BFS를 탐색하면 state-space에 0의 개수가 구해지고 그 중 가장 안전한 경우의 0의 개수를 구합니다.

2. 어려웠던 부분 + 발전해야 하는 부분

1) BFS의 시간복잡도를 명확하게 구하지 못했습니다.
- 탐색의 시간복잡도를 명확하게 구하지 못하였기 때문에 완전탐색을 시도하는데 주저함이 있었습니다.

2) 64C3
- 오랜만에 공부하여 잊어 버렸고 , 백준님의 N과M 문제집을 다시 풀었습니다.
- 간결하고 좋은 코드 : https://jaimemin.tistory.com/601 의 MakeWall(int cnt)

3) BFS
- BFS를 오랜만에 구현하다 보니 , 잦은 실수가 발생하였습니다.

4) iindex[3]
- 중요한 배열임에도 불구하고 이름이 매우 모호하여 , 디버깅 과정에서 제가 만든 배열이지만 의미파악에 오랜시간이 걸렸습니다.
*/
int n,m;
struct str
{
    int idx_1;
    int idx_2;
    int idx_3;
};
str obj;
vector<str> v;
vector<pair<int,int>> tmp;
int iindex[3]; //HARD
int old_arr[10][10];
int new_arr[10][10];
queue<pair<int,int>> q;
pair<int,int> path[4]= {{-1,0},{0,1},{1,0},{0,-1}};
int answer = 0;
int sum_zero = 0;

/*
- DFS의 조합 탐색을 이용하여 벽을 세울 수 있는 모든 경우(64C3)를 구해야 합니다.
- 백준 N*M 문제집에서 조합에 관한 연습을 할 수 있습니다.

*/

//Dfs + MakeWall : 64C3의 벽 세우기
void Dfs(int depth , int mmax)
{               
    if(depth == 3)
    {
        obj.idx_1 = iindex[0];
        obj.idx_2 = iindex[1];
        obj.idx_3 = iindex[2];   
        if(obj.idx_1 < obj.idx_2 && obj.idx_2 < obj.idx_3)
        {
            v.push_back(obj);
        }    
        return;
    } 
    for(int i=0; i<mmax; i++)
    { 
        iindex[depth] = i;
        Dfs(depth+1 , mmax);
    } 
}

void MakeWall()
{  
    int empty_cnt=0;   
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(old_arr[i][j] == 0)
            {    
                tmp.push_back({i,j});
                empty_cnt++;
            }
        }
    }  
    int mmax = tmp.size(); 
    Dfs(0,mmax); 
}

void Bfs()
{
    int visited[10][10];
    memset(visited , 0 , sizeof(visited));
    int row,col;
    sum_zero = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(new_arr[i][j] == 2)
            {
                q.push({i,j});
                visited[i][j] = 1;
                while(q.empty() != true)
                {
                    for(int k=0; k<4; k++)
                    {                       
                        row = q.front().first+path[k].first; //HARD: (i,j) -> q.front() , 정말 BFS를 안본지 오래되었다는 것을 느낍니다.
                        col = q.front().second+path[k].second;
                        if(new_arr[row][col] == 0)
                        {
                            new_arr[row][col] = 2;
                            visited[row][col] = 1;
                            q.push({row,col});
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(new_arr[i][j] == 0)
            {
                sum_zero++;
            }
        }
    }
    
    if(answer < sum_zero)
    {
        answer = sum_zero;      
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	  
    //입력 
    int num;
    cin >> n >> m;
    memset(old_arr,-1,sizeof(old_arr));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> num;
            old_arr[i][j] = num;           
        }
    }      
    MakeWall(); 

    for(unsigned int i=0; i<v.size(); i++)
    {
        memcpy(new_arr , old_arr , sizeof(new_arr));        
        new_arr[tmp[v[i].idx_1].first][tmp[v[i].idx_1].second] = 1;
        new_arr[tmp[v[i].idx_2].first][tmp[v[i].idx_2].second] = 1;
        new_arr[tmp[v[i].idx_3].first][tmp[v[i].idx_3].second] = 1;              
        Bfs();   
    }

    cout << answer;
   	return 0;
}
