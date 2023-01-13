#include "helper.h"

minMax iterativeMinMax(int *a, int size){
	int i, minL, minR, maxL, maxR;
	int left[size/2];
	int right[size/2];
	int middle = size/2;
	minMax vals;
	//Splits array a into two equally sized arrays (left and right sides of the array)
	for (i = 0 ; i<middle ; i++){
		left[i] = a[i];
		right[i] = a[i+middle];
	}
	//initializes all values to be the first index of their respective arrays
	minL = left[0];
	maxL = left[0];
	minR = right[0];
	maxR = right[0];
	//simeultaneously traverses each half or array a to find a min and max for the left and right sides
	for (i = 1; i < middle ; i++){
		if (minL > left[i]){
			minL = left[i];
		}
		if(maxL < left[i]){
			maxL = left[i];
		}
  		if (minR > right[i]){
                        minR = right[i];
                }
                if(maxR < right[i]){
                        maxR = right[i];
                }
	}
	//Compares the min and max values of the left and right side of the array to find the extremes
	if(minL < minR){
                vals.min = minL;
        }
        else{
                vals.min = minR;
        }

        if (maxL > maxR){
                vals.max = maxL;
        }
        else{
                vals.max = maxR;
        }
        return vals;
}
int main(){

        int i;
        int *n,size;
        minMax vals;
        printf("Enter the desired size of your array: \n");
        scanf("%d",&size);
        int a[size];
        printf ("Enter integer values for your array: \n");
        for(i = 0 ; i < size ; i++){
                scanf("%d" , &a[i]);
        }
        vals = iterativeMinMax(a,size-1);
        printf("Minimum: %d \n",vals.min);
        printf("Maximum: %d \n" ,vals.max);
        return 0;
}
