//#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
char num[10][10]= {"零","一","二","三","四","五","六","七","八","九"};
char ten[20][10]= {"","十","百","千"};
int main()
{
    int n,i,flag1,flag2,ans=0;
    char s[100];
    for(int w=1;w<=100000000;w++)
    {
        sprintf(s,"%d",w);
        n=strlen(s);
        flag1=0;
        flag2=0;
        for(i=0; i<n; i++)
        {
            if(s[i]!='0'&&flag1)
            {
                flag1=0;
//                printf("零");
                ans++;
            }
            if(s[i]=='0')
                flag1=1;
            else
            {
                flag2=1;
                if(i==0&&s[i]=='1'&&(n-i-1)%4==1)
                {
//                    printf("%s",ten[(n-i-1)%4]);
                    ans++;
                }
                else
                {
//                    printf("%s%s",num[s[i]-'0'],ten[(n-i-1)%4]);
                    if((n-i-1)%4!=0)
                        ans++;
                    ans++;
                }
            }
            if(flag2==1&&(n-i-1==4||n-i-1==12))
            {
                flag2=0;
//                printf("万");
                ans++;
            }
            if(n-i-1==8)
            {
                flag2=0;
//                printf("亿");
                ans++;
            }
        }
//        printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}
