#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	printf("Number of rows of the matrix：");
	scanf("%d",&n);
	
	double arr[201][402];
	printf("Write down the number row by row：");
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lf",&arr[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=n;j<2*n;j++){
			if(j==i+n) arr[i][j]=1;
			else arr[i][j]=0;
	}} 
	
	
	double ratio;
	for(int i=0;i<n-1;i++){
		for(int t=0;i+t<n;t++){
			if(arr[i+t][i]!=0){
				for(int s=i;s<2*n;s++){
					double temp;
					temp=arr[i][s];
					arr[i][s]=arr[i+t][s];
					arr[i+t][s]=temp;
		}}}		
		
		for(int k=0;i+k<n-1;k++){
			ratio=arr[k+1+i][i]/arr[i][i];
			for(int j=i;j<2*n;j++){
				arr[i+k+1][j]=arr[i+1+k][j]-arr[i][j]*ratio;
		}}
	}

	for(int i=n-1;i>0;i--){
		for(int k=1;i-k>=0;k++){
			ratio=arr[i-k][i]/arr[i][i];
			for(int j=i;j<2*n;j++){
				arr[i-k][j]-=arr[i][j]*ratio;
	}}}
		
	for(int i=0;i<n;i++){

		ratio=arr[i][i];
		for(int j=i;j<2*n;j++){
			arr[i][j]/=ratio;
		}
	}

	
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=n;j<2*n;j++){
		printf("%lf ",arr[i][j]);
	}}	
	return 0;
}
