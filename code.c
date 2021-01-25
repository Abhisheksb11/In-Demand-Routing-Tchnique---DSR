#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[5],rep[5],n,recv,i,ttl;
    char ip[100][100];
    char ch;
    printf("Enter type of packet 1/2/3\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:req[0]=n;
            printf("Enter route request packet:(srcnode,seqno,dstnode,ttl)\n");
            for(i=1;i<5;i++)
                scanf("%d",&req[i]);
            printf("The route request packet:\n");
            printf("\nType sourcenode seqno Destnode TTL\n");
            for(i=0;i<5;i++)
                printf("%d\t",req[i]);
            printf("\nEnter receiving node:");
            scanf("%d",&recv);
            ttl=req[4]-1;
            if(ttl==0)
            {
                printf("Packet is discarded");
                exit(0);
            }
            printf("\nEnter route request packet received by node:\n");
            if(ttl!=0)
                for(i=1;i<5;i++)
                    printf("%d\t",req[i]);
                printf("\nPacket received");
            break;

        case 2:rep[0]=n;
            printf("Enter route reply packet:\n");
            for(i=1;i<5;i++)
                scanf("%d",&req[i]);
            printf("Do you want to generate route to destination?y/n\n");
            scanf("%s",&ch);
            if(ch=='y'|| ch=='Y')
            {
                printf("\nType sourcenode seqno Destnode TTL\n");
                for(i=1;i<5;i++)
                    printf("%d\t",req[i]);
                printf("\nEnter receiving node:");
                scanf("%d",&recv);
                ttl=req[4]-1;
                if(ttl==0)
                {
                    printf("Packet is discarded");
                    exit(0);
                }
                 printf("\nEnter route request packet received by node:\n");
                if(ttl!=0)
                    for(i=1;i<5;i++)
                        printf("%d\t",req[i]);
                    printf("\nPacket received");
            }
            else
            {
                printf("Enter how many intermediate node:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter intermediate ip address %d\n",i+1);
                    scanf("%s",ip[i]);
                }
                for(i=0;i<n;i++)
                {
                    printf("\nIntermediate ip address %d\t",i+1);
                    printf("%s",ip[i]);
                }
            }
            break;

        case 3:printf("Error\n");
            break;
        }
    return 0;
}
