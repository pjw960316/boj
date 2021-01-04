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

int arr[31][31];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    bool same = true;
	int n,row,col;
    string str;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        for(int j=0; j<n; j++)
        {
            arr[i][j] = str[j];
        }
    }
    
    //row move
    for(int i=0;i<n; i++)
    {
        row = i;
        same = true;
        for(int j=1;j<n;j++)
        {
            if(arr[i][0] == '.')
            {
                same = false;
                break;
            }
            if(arr[i][0] != arr[i][j])
            {
                same = false;
                break;
            }
        }
        if(same == true)
        {
            printf("%c" , arr[row][0]);
            return 0;
        }
    }
    //column move
    for(int i=0;i<n; i++)
    {
        col = i;
        same = true;
        for(int j=1;j<n;j++)
        {
            if(arr[0][i] == '.')
            {
                same = false;
                break;
            }
            if(arr[0][i] != arr[j][i])
            {
                same = false;
                break;
            }
        }
        if(same == true)
        {
            printf("%c" , arr[0][col]);
            return 0;
        }
    }
    //diagonal move
    for(int i=1; i<n; i++)
    {
        same = true;
        if(arr[0][0] == '.')
        {
            same = false;
            break;        
        }
        if(arr[0][0] != arr[i][i])
        {
            same = false;
            break;
        }
        if(same == true)
        {
            printf("%c" , arr[0][0]);
            return 0;
        }
    }
    for(int i=1; i<n; i++)
    {
        same = true;
        if(arr[n-1][0] == '.')
        {
            same = false;
            break;        
        }
        if(arr[n-1][0] != arr[n-1-i][0+i])
        {
            same = false;
            break;
        }
        if(same == true)
        {
            printf("%c" , arr[n-1][0]);
            return 0;
        }
    }
    printf("ongoing");
 	return 0;
}
