#include<stdio.h>
#include<string.h>

struct dirct
{
    char dir[10],file[20][10];
    int findex;
};

void main()
{
    int i,j,found=0,dindex=0,ch=1;
    struct dirct d[10];
    char ser[10];
    for(i=0;i<10;i++)
        d[i].findex=0;
    do
    {
        printf("1.Create directory\n2.Create File\n3.Delete File\n4.Search File\n5.List Files\n0.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter directory name:");
            scanf("%s",d[dindex].dir);
            dindex++;
            printf("Directory Created\n");
            break;

            case 2:
            printf("Enter Directory:");
            scanf("%s",&ser);
            for(i=0;i<dindex;i++)
            {
                if(!strcmp(ser,d[i].dir))
                {
                    printf("\nEnter File name:");
                    scanf("%s",&d[i].file[d[i].findex++]);
                    printf("File created..\n");
                    break;

                }
            }
            if(i==dindex)
            {
                printf("No such file or directory\n");
            }
            break;

            case 3:
            printf("Enter file to be deleted:");
            scanf("%s",ser);
            found=0;
            for(i=0;i<dindex;i++){
                for(j=0;j<d[i].findex;j++){
                    if(!strcmp(ser,d[i].file[j]))
                    {
                        printf("\nThe file is removed\n");
                        strcpy(d[i].file[j],d[i].file[d[i].findex-1]);
                        d[i].findex--;
                        found=1;
                        break;
                    }
                }
            if(!found)
            {
                printf("No such file or directory..\n");
            }
            }
            break;

            case 4:
            printf("Enter file to be searched:");
            scanf("%s",ser);
            found=0;
            for(i=0;i<dindex;i++){
                for(j=0;j<d[i].findex;j++){
                    if(!strcmp(ser,d[i].file[j])){
                        printf("File found at %dth position in %s directory",d[i].findex,d[i].dir);
                        found=1;
                        break;
                    }
                }
            }
            if(!found)
            {
                printf("No such file or directory\n");
            }
            break;

            case 5:
            for(i=0;i<dindex;i++)
            {
                printf("Files in %s directory are:",d[i].dir);
                for(j=0;j<d[i].findex;j++)
                {
                    printf("%s\n",d[i].file[j]);
                }
            }
            break;
        }
    } while (ch);
}