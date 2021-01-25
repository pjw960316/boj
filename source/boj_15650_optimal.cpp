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
int n,m;
int arr[10];
void Dfs(int idx , int depth)
{
	if(depth > m)
	{
		for(int i=1; i<=m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=idx;i<=n; i++)
	{
		arr[depth] = i;
		Dfs(i+1 , depth+1);
	}
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> n >> m;
	Dfs(1,1);
	return 0;
}


