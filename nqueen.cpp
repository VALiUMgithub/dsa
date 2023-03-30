// Begin
//    if there is a queen at the left of current col, then
//       return false
//    if there is a queen at the left upper diagonal, then
//       return false
//    if there is a queen at the left lower diagonal, then
//       return false;
//    return true //otherwise it is valid place
// End
// solveNQueen(board, col)
// Begin
//    if all columns are filled, then
//       return true
//    for each row of the board, do
//       if isValid(board, i, col), then
//          set queen at place (i, col) in the board
//          if solveNQueen(board, col+1) = true, then
//             return true
//          otherwise remove queen from place (i, col) from board.
//       done
//    return false
// End


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int a[30],count=0;
int place(int pos)
{
int i;
for (i=1;i<pos;i++) {
if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
return 0;
}
return 1;
}
void print_sol(int n) {
int i,j;
count++;
printf("\n\nSolution #%d:\n",count);
for (i=1;i<=n;i++) {
for (j=1;j<=n;j++) {
if(a[i]==j)
printf("Q\t"); elseprintf("*\t");
}
printf("\n");
}
}
void queen(int n) {
int k=1;
a[k]=0;
while(k!=0) {
a[k]=a[k]+1;
while((a[k]<=n)&&!place(k))
a[k]++;
if(a[k]<=n) {
if(k==n)
print_sol(n); else {
k++;
a[k]=0;
}
} else
k--;
}
}
void main() {
int i,n;
printf("Enter the number of Queens\n");scanf("%d",&n);
queen(n);
printf("\nTotal solutions=%d",count);
getch();
}
