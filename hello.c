#include<stdio.h>
#include<string.h>

struct Name
{
    char name[21];

};

int main()
{
    int n;
    scanf("%d",&n);
    struct Name names[n];
    for (int i = 0;i < n;i++)
    {
        fgets(names[i].name,n,stdin);
        for (int j = 0;j < i;j++)
        {
            if (names[i].name != names[j].name)
            {
                printf("No\n");

            }
        }
    }
    printf("Yes\n");


    return 0;


}
