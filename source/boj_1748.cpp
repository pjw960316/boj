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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	 
    int n,len,sum=0;
    string str;
    cin >> n;
    str = to_string(n);
    len = str.size();
    if(len == 1)
    {
        cout << n;
        return 0;
    }
    for(int i=0; i<len-1; i++)
    {
        sum += pow(10,i)*9*(i+1);
    }
    sum += (n-pow(10,len-1)+1)*len;
    cout << sum;
	return 0;
}
