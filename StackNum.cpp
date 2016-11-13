#include <iostream>

using namespace std;

int SeqNum(int x,int y) //x:进栈的总个数 y:出栈的总个数
//从(0,0)到(n,n)，只能向右走或者向上走
{
    if(y==0)
    {
        return 1;
    }
    if(y==x)
    {
        return SeqNum(x,y-1);
    }
    if(x>y)
    {
        return SeqNum(x-1,y)+SeqNum(x,y-1);
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cin >> n;
    //cout << "Hello world!" << endl;
    cout << SeqNum(n,n) << endl;
    return 0;
}
