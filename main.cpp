#include <iostream>

using namespace std;

int SeqNum(int x,int y) //x:��ջ���ܸ��� y:��ջ���ܸ���
//��(0,0)��(n,n)��ֻ�������߻���������
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
