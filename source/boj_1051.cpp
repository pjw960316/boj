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
- 문제를 제대로 읽지 않아서 사각형이 평행하다는 부분을 놓쳤습니다.
- 다시 읽고 복잡도가 50^3이므로 해결했습니다.
- 사각형의 한 변의 길이가 최대 길이인 모든 경우 -> 한 변의 길이가 1인 사각형

2. 어려웠던 부분
- x
*/

int arr[500][500];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    memset(arr , -1 , sizeof(arr));
    int n,m;
    string num;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        for(int j=0; j<m; j++)
        {
            arr[i][j] = num[j] - '0';
        }
    }
  
    int limit = min(n,m);
    for(int len=limit; len>=0; len--)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j] == arr[i+len][j] && arr[i][j] == arr[i][j+len] && arr[i][j] == arr[i+len][j+len])
                {
                    cout << (len+1)*(len+1);
                    return 0;
                }
            }
        }
    }
	return 0;
}


