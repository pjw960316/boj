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

int arr[600][600];
/*
1. 풀이과정
1) 시간복잡도를 계산합니다.
- 1회 탐색이 500*500입니다. 
- 5개의 도형의 경우가 과장해서 100개라고 잡아도 
500*500*100 <1억 -> brute force
2) 모든 경우를 계산합니다.
- 반복되는 기능이 전부이므로 함수를 만들면 될 것 같았습니다.
하지만 노트에 경우를 모두 나열해본 결과 20개도 되지 않았고 
그냥 복사 붙여넣기로 해결했습니다.
2. 어려웠던 부분
1) 노트와 에디터의 동선
- 5개의 도형을 구하는 과정에서 1개를 노트에서 구하고 에디터에서 코딩을 했습니다.
5개의 도형을 모두 구해보고 에디터에서 한 번에 했으면 좋았을 듯 합니다.
2) 함수화
- 이런 단순 브루트 포스를 함수를 사용하지 않으면 실수가 발생하기 좋습니다.
- 하지만 실전에서 함수를 사용할 생각을 할까???
*/

/*
코포 블루의 코드
- 나는 반복문을 많이 썼지만 이 사람은 어차피 최대 값이므로 하나의
반복문에 모두 넣어서 시간복잡도를 나의 1/20 수준으로 최적화 시켰습니다.
#include <iostream>
using namespace std;
int v[510][510];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &v[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans = max(ans, v[i][j] + v[i+1][j] + v[i+2][j] + v[i+3][j]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i][j+2] + v[i][j+3]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j] + v[i+1][j+1]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j] + v[i][j+2]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j] + v[i+2][j]);
            ans = max(ans, v[i][j] + v[i+1][j] + v[i+1][j+1] + v[i+1][j+2]);
            ans = max(ans, v[i][j] + v[i+1][j] + v[i+2][j] + v[i+2][j+1]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j+1] + v[i+2][j+1]);
            ans = max(ans, v[i+1][j] + v[i+1][j+1] + v[i][j+2] + v[i+1][j+2]);
            ans = max(ans, v[i+2][j] + v[i][j+1] + v[i+1][j+1] + v[i+2][j+1]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i][j+2] + v[i+1][j+2]);
            ans = max(ans, v[i][j] + v[i+1][j] + v[i+1][j+1] + v[i+2][j+1]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j+1] + v[i+1][j+2]);
            ans = max(ans, v[i][j+1] + v[i+1][j] + v[i+1][j+1] + v[i+2][j]);
            ans = max(ans, v[i][j+1] + v[i+1][j] + v[i+1][j+1] + v[i][j+2]);
            ans = max(ans, v[i][j] + v[i][j+1] + v[i+1][j+1] + v[i][j+2]);
            ans = max(ans, v[i][j] + v[i+1][j] + v[i+1][j+1] + v[i+2][j]);
            ans = max(ans, v[i][j+1] + v[i+1][j] + v[i+1][j+1] + v[i+1][j+2]);
            ans = max(ans, v[i][j+1] + v[i+1][j] + v[i+1][j+1] + v[i+2][j+1]);
        }
    }
    printf("%d", ans);
}
*/
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int sum = 0, mmax = 0;

    for(int i=0; i<600;i++)
    {
        for(int j=0; j<600; j++)
        {
            arr[i][j] = -99999;
        }
    }
    int n,m,num;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }

    //ㅁㅁㅁㅁ
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    /*
    ㅁㅁ
    ㅁㅁ
    */
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    /*
    ㅁ
    ㅁ
    ㅁㅁ
    */
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j-1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i-1][j+2];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    /*
    ㅁ
    ㅁㅁ
     ㅁ
     */
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j-1]+arr[i+2][j-1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i-1][j+2];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    /*
     ㅁ
    ㅁㅁㅁ
    */
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i-1][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i+1][j+1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {   
            sum = arr[i][j]+arr[i-1][j-1]+arr[i][j-1]+arr[i+1][j-1];
            if(mmax < sum)
            {
                mmax = sum;
            } 
        }
        sum=0;
    }

    cout << mmax;
	return 0;
}