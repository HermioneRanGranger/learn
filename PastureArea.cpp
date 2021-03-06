#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

double Area(int a,int b, int c) //计算面积
{
    double s=0,p=0;
    if(a+b<=c || a+c<=b || b+c<=a) //not a 三角形
    {
        return -1;
    }
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;

}

int main()
{
    int n;
    cin >> n; //木板个数
    int i=0,j=0,k=0;
    int L[40];
    int sum=0;
    double s=-1,temp=0;
    for(i=0;i<n;i++)
    {
        cin>>L[i];
        sum += L[i]; //total length
    }
    //a+b>c,a+b+c=sum,then c<sum/2
    bool dp[800][800];//40*40 /2
    memset(dp[0], 0,800*800); //first initialize
    dp[0][0]=1;

    for(k=0;k<n;k++) //每个木块独立，并不可以拼一起了再随意切成两块
        //k=0，i,j总共最多只有前1块的可能组合;(第1块 取/不取 dp都为1，代表符合上面一句注释
        //k=1，i,j总共最多只有前2块的可能组合，(第2块，取/不取 dp都为1 依次类推
    {
        for(i=sum/2;i>=0;i--) //限制一下
        {
            for(j=sum/2;j>=0;j--)
            {
                if(i>=L[k])
                {
                    dp[i][j]=dp[i-L[k]][j] || dp[i][j];
                }
                if(j>=L[k])
                {
                    dp[i][j]=dp[i][j-L[k]] || dp[i][j];
                }
                if(dp[i][j]==1 && i!=0 && j!=0)//可以先做一点限制
                {
                    temp=Area(i,j,sum-i-j);
                    if(temp>s) s=temp;
                }
            }
        }
    }
    if(s!=-1)
    {
        cout << int (s*100) <<endl;
    }
    else
        cout << s <<endl;

    //cout << "Hello world!" << endl;
    return 0;
}
