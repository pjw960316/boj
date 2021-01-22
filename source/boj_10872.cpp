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

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;    
    cin >> n;
    if(n==0)
    {
        cout << 1;
        return 0;
    }
    int answer = n;
    while(n-- > 1)
    {
        answer *= n;
    }
    cout << answer;
	return 0;
}


