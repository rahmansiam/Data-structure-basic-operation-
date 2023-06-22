#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct Student
{
    char name[100];
    int id;
    int marks;
};
struct Uniqe_student
{
    char name[100];
    int id;
    int total;
};
int main()
{   FILE *inputFile = fopen("input.txt","r");
    if (inputFile == NULL)
    {
        printf("File not found!");
    }
    FILE *outputFile = fopen("output.txt","w");
    int n;
    fscanf(inputFile,"%d",&n);
    struct Student students[n];
    struct Uniqe_student uniqe_student[n];
    int k = 0;
    bool found = false;
    for (int i = 0;i < n;i++)
    {
        fscanf(inputFile,"%s %d %d",&students[i].name,&students[i].id,&students[i].marks);
        for (int j = 0;j < k;j++)
        {
            if (uniqe_student[j].id == students[i].id)
            {
                uniqe_student[j].total += students[i].marks;
                found = true;
            }
        }
        if (found == false)
        {
            strcpy(uniqe_student[k].name,students[i].name);
            uniqe_student[k].id = students[i].id;
            uniqe_student[k].total = students[i].marks;
            k++;
        }
    }
    for (int i = 0;i < k-1;i++)
    {
        for (int j = i+1;j < k;j++)
        {
            if(uniqe_student[i].total < uniqe_student[j].total)
            {
                struct Uniqe_student tmp = uniqe_student[i];
                uniqe_student[i] = uniqe_student[j];
                uniqe_student[j] = tmp;
            }
        }
    }
    for (int i = 0;i < k;i++)
    {
        fprintf(outputFile,"%s %d %d\n",uniqe_student[i].name,uniqe_student[i].id,uniqe_student[i].total);
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
