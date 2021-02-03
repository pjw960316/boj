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
#define ULL unsigned long long
using namespace std;

/*
1. 풀이 과정

2. 어려웠던 부분

*/

ULL arr[1002];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++)
    {
        arr[i] = (arr[i-2] + arr[i-1])%10007;
    }
    cout << arr[n];
	return 0;
    

}


