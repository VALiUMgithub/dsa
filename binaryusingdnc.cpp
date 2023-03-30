#include <stdio.h>
#define MAX 20
int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
void printline(int count) {
int i;
for(i = 0;i <count-1;i++) {
printf("=");
}
printf("=\n");
}
int find(int data) {
int lowerBound = 0;
int upperBound = MAX -1;
int midPoint = -1;
int comparisons = 0;
int index = -1;
while(lowerBound <= upperBound) {
printf("Comparison %d\n" , (comparisons +1) );
printf("lowerBound : %d, intArray[%d] = %d\n",lowerBound,lowerBound,
intArray[lowerBound]);
printf("upperBound : %d, intArray[%d] = %d\n",upperBound,upperBound,
intArray[upperBound]);
comparisons++;midPoint = lowerBound + (upperBound - lowerBound) / 2;
if(intArray[midPoint] == data) {
index = midPoint;
break;
} else {
if(intArray[midPoint] < data) {
lowerBound = midPoint + 1;
}
else {
upperBound = midPoint -1;
}
}
}
printf("Total comparisons made: %d" , comparisons);
return index;
}
void display() {
int i;
printf("[");
for(i = 0;i<MAX;i++) {
printf("%d ",intArray[i]);
}
printf("]\n");}
void main() {
printf("Input Array: ");
display();
printline(50);
int location = find(55);
if(location != -1)
printf("\nElement found at location: %d" ,(location+1));
else
printf("\nElement not found.");
}
