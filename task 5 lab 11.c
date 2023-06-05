#include<stdio.h>

int* countEven(int *arr, int n, int *count)
{
    int i = 0;
	int j = 0;
    int *ptr = (int*)malloc(n*sizeof(int));
    
	while(i < n)
	{
		if (*(arr+i) % 2 == 0)
		{
//			printf("value = %d\n",*(arr+i));
			*(ptr+j) = *(arr+i);
			j++;
			*count = *count + 1;
//			printf("count = %d\n",*count);
		}
		i++;
	}
	return ptr;
}


int main()
{
	int i,j,n,arr[100],count;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the elements in array:");

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
//	int j = 0;
	int* result = countEven(arr, n, &count);
	printf("The even number is:");
    for(j=0; j<count; j++)
	{
    	printf("\n%d\n",*(result+j));
	}
}

