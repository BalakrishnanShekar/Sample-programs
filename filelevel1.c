#include<stdio.h>
#include<string.h>

struct dirct{
    char dir[10],file[20][10];
    int findex;
};
void main()
{
    int ch=1,i;
    char ser[10];
    struct dirct d;
    d.findex=0;
    printf("Enter directory name:");
    scanf("%s",&d.dir);
    do{
        printf("1.Create File\n2.Delete File\n3.Search File\n4.List Files\n0.Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter File name:");
            scanf("%s",d.file[d.findex++]);
            printf("File created..\n");
            break;

            case 2:
            printf("Enter File to be deleted:");
            scanf("%s",&ser);
            for(i=0;i<d.findex;i++)
            {
                if(!strcmp(ser,d.file[i]))
                {
                    printf("\nFile deleted\n");
                    strcpy(d.file[i],d.file[d.findex-1]);
                    d.findex--;
                    break;
                }
                if(i==d.findex)
                {
                printf("\nNo such file or directory\n");
                }
            }
            break;
            

            case 3:
            printf("Enter file to be searched:");
            scanf("%s",ser);
            for(i=0;i<d.findex;i++)
            {
                if(!strcmp(ser,d.file[i]))
                {
                    printf("File is found in %dth position\n",i+1);
                    break;
                }
                if(i==d.findex)
                {
                printf("No such file or directory\n");
                }
            }
            break;

            case 4:
            printf("Files in the directory %s are:\n",d.dir);
            for(i=0;i<d.findex;i++)
            {
                printf("%s\n",d.file[i]);
            }
            break;
        }
    }
    while(ch);
}