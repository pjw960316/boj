#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
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

2. 어려웠던 부분

*/
int arr[10];
int n,m;

void Dfs(int depth)
{
    if(depth == m)
    {        
        for(int i=1; i<=n; i++)
        {
            arr[depth] = i;
            for(int j=1; j<=depth; j++)
            {
                cout << arr[j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(int i=1; i<=n; i++)
    {
        arr[depth] = i;
        Dfs(depth+1);
    }
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    cin >> n >> m;
    arr[0] = 1;
    Dfs(1);
	return 0;
}


