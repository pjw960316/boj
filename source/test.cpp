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

2. 어려웠던 부분

*/

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    string str = "abcd";
    for(auto i : str)
    {
        if(i=='b')
            cout << i;
    }
	return 0;
}

