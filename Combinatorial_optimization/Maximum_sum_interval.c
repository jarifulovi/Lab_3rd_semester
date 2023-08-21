#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {-3,1,-8,2,2,-3,2};
    int length = sizeof(arr) / sizeof(int);
    int curr = 0, max_sum = INT_MIN;
    int start = 0, end = 0; 

    for (int i = 0; i < length; i++) {
        if (curr <= 0) {
            curr = arr[i];
            if(curr>max_sum)  start = i;
        } 
        else {
            curr += arr[i];
        }

        if (curr > max_sum) {
            max_sum = curr;
            end = i; // Update end index
        }
    }
    printf("The maximum sum is %d\n",max_sum);
    printf("The maximum sum interval[%d,%d] : ",start,end);
    for(int i=start;i<=end;i++)
        printf("%d ",arr[i]);
    return 0;
}
