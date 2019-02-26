#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, i,j ;
	printf("此矩陣的行向量維度為：");
	scanf("%d",&n);
	
	double a[201][402];
	printf("請一行一行輸入值：");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			if(j==i+n){
				a[i][j]=1;
			}
			else{
				a[i][j]=0;
	}}} 
	
	
	double b, m;
	
	for(i=0;i<n-1;i++){
		
		for(int t=0;i+t<n;t++){
			if(a[i+t][i]!=0){
				for(int s=i;s<2*n;s++){
					m=a[i][s];
					a[i][s]=a[i+t][s];
					a[i+t][s]=m;
		}}}		
		
		for(int k=0;i+k<n-1;k++){
			b=a[k+1+i][i]/a[i][i];
			for(j=i;j<2*n;j++){
				a[i+k+1][j]=a[i+1+k][j]-a[i][j]*b;
		}}
	}

	for(i=n-1;i>0;i--){
		for(int k=1;i-k>=0;k++){
			b=a[i-k][i]/a[i][i];
			for(j=i;j<2*n;j++){
				a[i-k][j]-=a[i][j]*b;
	}}}
		
	for(i=0;i<n;i++){

		b=a[i][i];
		for(j=i;j<2*n;j++){
			a[i][j]=a[i][j]/b;
		}
	}

	
	for(i=0;i<n;i++){
		printf("\n");
		for(j=n;j<2*n;j++){
		printf("%lf ",a[i][j]);
	}}	
	return 0;
}
