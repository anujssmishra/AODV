#include<stdio.h>
#define RTSIZE 100   

struct RE{             //structure containing router entries within routing table
    char dest[16];
    char nextHop;
    int numberOfHops;
    int sequenceNo;
}rtable[100];
 
union ipToInt{
    char ip[16];
    unsigned long int n;
};
 
void main()
{
     //defining size for routing table
    union ipToInt ipl;
    char choice;
    int i;
    printf("Please enter \n'L' for lookup, \n'A' for adding a route, or \n'D' for deleting a route in the routing table:    ");
    scanf("%c", &choice);
    while(choice!='0'){
        switch(choice){
        case 'L':
            printf("Please input IP address to be looked up in routing table:"   );
            scanf("%s", ipl.ip);
            for(i=0;i<=RTSIZE;i++)
                if(rtable[i].dest == ipl.ip){
                    printf("Route for %s goes via node %d has sequence number %d and has %d Hops.", rtable[i].dest,rtable[i].nextHop,rtable[i].sequenceNo,rtable[i].numberOfHops);
            }else  {
                printf("Route for %s is unknown and should be redirected to the designated router.", ipl.ip);
            }
        break;
    case 'A':
        for (i = 0; i <= RTSIZE; i++){
            if (rtable[i].link == 0){
                printf("Please input IP Address, to be added into routing table:     ");
                scanf("%s", &rtable[i].dest);
                printf("Please input number of hops to be added along with presented IP address:     ");
                scanf("%d", &rtable[i].numberOfHops);
                printf("Please input the next hop associated with IP address:     ");
                scanf("%d", &rtable[i].nextHop);
		printf("Please input the sequence number : ");
		scanf("%d", &rtable[i].sequenceNo)
                printf("Route added for %s\n", rtable[i].dest);
                rtable[i].link = 1;
                printf("%d port, %d hops\n", rtable[i].port, rtable[i].hops);
                printf("%d link value\n", rtable[i].link);
                printf("%d value of i\n", i);
                break;
                }
        }
    //case 'D':
      //    deleteroute();
        //  break;
          //default:
        }  scanf("%c", &choice);
}};
