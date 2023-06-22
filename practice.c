#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100];
    scanf("%s",&ar);
    int i = 0,j = strlen(ar)-1;
    while(1)
    {

        if (i < j)
        {
            printf("%c\n",ar[i]);
            printf("j = %c\n",ar[j]);

        }
        break;
//        if (j > i)
//        {
//            continue;
//        }
        i++;
        j--;
    }

    return 0;
}
