// Begin
//    Define a variable vr = 4 universally.
//    Declare an integer function TSP to implement Travelling salesman Problem.
//    Declare a graph grph[][] as a 2D matrix and variable p to the integer datatype.
//    Pass them as a parameter.
//    Declare variable ver to the vector datatype.
//    for (int i = 0; i < vr; i++)
//       if (i != p) then
//          Call push_back(i) function to store the value of all vertex except source vertex.
//          Initialize m_p = INT_MAX to store minimum weight of a graph.
//       do
//          Declare cur_pth, k to the integer datatype.
//             initialize cur_pth = 0.
//             initialize k = p.
//          for (int i = 0; i < ver.size(); i++)
//             cur_pth += grph[k][ver[i]].
//             k = ver[i].
//          cur_pth += grph[k][p].
//          m_p = min(m_p, cur_pth) to update the value of minimum weight.
//          while (next_permutation(ver.begin(), ver.end())).
//          Return m_p.
//    Declare a graph grph[][] as a 2D matrix to the integer datatype.
//       Initialize values of grph[][] graph.
//    Declare variable p to the integer datatype.
//       Initialize p = 0.
//    Print “The result is: ”.
//    Print the return value of TSP() function.
// End.


#include<stdio.h>
int ary[10][10],completed[10],n,cost=0;
void takeInput()
{
int i,j;
printf("Enter the number of villages: ");
scanf("%d",&n);
printf("\nEnter the Cost Matrix\n");
for(i=0;i < n;i++)
{
printf("\nEnter Elements of Row: %d\n",i+1);
for( j=0;j < n;j++)
scanf("%d",&ary[i][j]);
completed[i]=0;
}
printf("\n\nThe cost list is:");
for( i=0;i < n;i++)
{
printf("\n");
for(j=0;j < n;j++)
printf("\t%d",ary[i][j]);
}
}
void mincost(int city){
int i,ncity;
completed[city]=1;
printf("%d--->",city+1);
ncity=least(city);
if(ncity==999)
{
ncity=0;
printf("%d",ncity+1);
cost+=ary[city][ncity];
return;
}
mincost(ncity);
}
int least(int c)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];nc=i;
}
}
if(min!=999)
cost+=kmin;
return nc;
}
int main()
{
takeInput();
printf("\n\nThe Path is:\n");
mincost(0);
printf("\n\nMinimum cost is %d\n ",cost);
return 0;
}
