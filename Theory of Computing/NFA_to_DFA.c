#include <stdio.h>
 int nfa[4][3];
void convertNFAtoDFA(int nfa_states,int nfa_symbols,int starting_state,int final_state){
    int dfa[10][2];
    int dstate[10];
    int i=1,n,j,k,flag=0,m,q,r;
    dstate[i++]=1;
    n=i;

    dfa[1][1]=nfa[1][1];
    dfa[1][2]=nfa[1][2];
    printf("\nf(%d,0)=%d",dstate[1],dfa[1][1]);
    printf("\nf(%d,1)=%d",dstate[1],dfa[1][2]);

    for(j=1;j<n;j++)
    {
        if(dfa[1][1]!=dstate[j])
          flag++;
    }
    if(flag==n-1)
    {
        dstate[i++]=dfa[1][1];
        n++;
    }
    flag=0;
    for(j=1;j<n;j++)
    {
         if(dfa[1][2]!=dstate[j])
            flag++;
    }
    if(flag==n-1)
    {
         dstate[i++]=dfa[1][2];
         n++;
    }
    k=2;
    while(dstate[k]!=0)
    {
        m=dstate[k];
        if(m>10)
        {
            q=m/10;
            r=m%10;
        }
        if(nfa[r][1]!=0)
             dfa[k][1]=nfa[q][1]*10+nfa[r][1];
        else
            dfa[k][1]=nfa[q][1];
        if(nfa[r][2]!=0)
            dfa[k][2]=nfa[q][2]*10+nfa[r][2];
        else
            dfa[k][2]=nfa[q][2];

        printf("\nf(%d,0)=%d",dstate[k],dfa[k][1]);
        printf("\nf(%d,1)=%d",dstate[k],dfa[k][2]);

       flag=0;
        for(j=1;j<n;j++)
        {
         if(dfa[k][1]!=dstate[j])
          flag++;
        }
      if(flag==n-1)
     {
        dstate[i++]=dfa[k][1];
        n++;
     }
    flag=0;
    for(j=1;j<n;j++)
    {
         if(dfa[k][2]!=dstate[j])
            flag++;
    }
    if(flag==n-1)
    {
         dstate[i++]=dfa[k][2];
         n++;
    }
    k++;
    }
}
int main()
{
    // the transition function for a string ends with 01
    /*nfa[1][1]=12;
      nfa[1][2]=1;
      nfa[2][1]=0;
      nfa[2][2]=3;
      nfa[3][1]=0;
      nfa[3][2]=0;*/

    int nfa_states,nfa_symbols,starting_state,final_state;
    printf("Enter states of nfa(3 for 1,2,3)\n");
    scanf("%d",&nfa_states);

    printf("Enter symbols of nfa(2 for 0 and 1)\n");
    scanf("%d",&nfa_symbols);

    printf("Enter transition function(for multiple states like 1 and 2 write 12)\n");
    for(int i=1;i<=3;i++){
        for(int j=1;j<=2;j++){
            printf("f(%d,%d) : ",i,j);
            scanf(" %d",&nfa[i][j]);
        }
    }
    printf("Enter starting state\n");
    scanf("%d",&starting_state);
    printf("Enter final states\n");
    scanf("%d",&final_state);
    printf("\n");
    convertNFAtoDFA(nfa_states,nfa_symbols,starting_state,final_state);
    return 0;
}
