#include <iostream>
#include <stdio.h>

int arr[102400];
int n;
inline void fan(int st,int en)
{
    while(st<=en)
        std::swap(arr[st++],arr[en--]);
}

void out()
{
    for(int a=1;a<=n;a++)
        printf("%d ",arr[a]);
    puts("");
}

int main()
{
    freopen("disk.in","r",stdin);
    freopen("disk.out","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int a=1;a<=n;a++)
            scanf("%d",&arr[a]);
        for(int a=2;a<=n;a++)
            if(arr[a]<arr[a-1]) //start at a-1     continue to find b
            {
                int b=a;
                while(b<=n)
                {
                    if(arr[b]<arr[b+1])b++;
                    else break;
                }
                fan(a-1,b-1);
                a=b;
                //puts("Fuck");
                //out();
            }
        bool flag=true;
        //out();
        for(int a=2;a<=n;a++)
            if(arr[a]<arr[a-1])
                flag=false;
        if(flag)
            puts("Y");
        else
            puts("J");
    }
    return 0;
}

