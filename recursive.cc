#include "helper.h"

minMax recursiveMinMax (int *a , int start , int end){
    	int middle;
	minMax vals, valsLeft, valsRight;

	//If there is only one element, return that element as both max and min
        if (start == end) {
                vals.min = a[start];
		vals.max = a[start];
		return vals;
        }

	//If there are two elements, compare them and set the larger one to max and the smaller to min
        if (start == end-1) {
                if(a[start] < a[end]){
                        vals.min = a[start];
                        vals.max = a[end];
			return vals;
                }
                else{
                        vals.min = a[start];
                        vals.max = a[end];
			return vals;
          	}
        }
        middle = (end+start)/2; //finds the midpoint index of the array
	valsLeft = recursiveMinMax(a, start, middle-1);//recursively calls recursiveMinMax, passing it the left side of the array
	valsRight = recursiveMinMax(a,middle, end);//recursively calls recursiveMinMax, passing it the right side of the array
	
	//Comparisons to determine if right side min and max or left side min and max are more extreme, and assigns the extremes to vals

	if(valsLeft.min < valsRight.min){
		vals.min = valsLeft.min;
	}
	else{
		vals.min = valsRight.min;
	}

	if (valsLeft.max > valsRight.max){
                vals.max = valsLeft.max;
        }
        else{
                vals.max = valsRight.max;
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
        printf ("Enter integer values for your array: ");
	//fills array a with user inputs
        for(i = 0 ; i < size ; i++){
                scanf("%d" , &a[i]);
        }
        vals = recursiveMinMax(a,0,size-1);
	printf("Minimum: %d \n",vals.min);
	printf("Maximum: %d \n" ,vals.max);
        return 0;
}
