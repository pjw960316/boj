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

int two=0;
int five=0;

void Divide(int n)
{
    while(n%2 == 0)
    {
        n /= 2;
        two++;
    }
    while(n%5 == 0)
    {
        n /= 5;
        five++;
    }
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=2; i<=n; i++)
    {
        Divide(i);
    }    
    cout << min(two , five);
	return 0;
}
