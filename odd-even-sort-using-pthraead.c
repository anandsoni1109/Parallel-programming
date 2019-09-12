#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

int n;
int *a;

void *matvec(void *k){
	int *count=(int*)k;
	printf("We are in thread  %d\n",a[*count]);
	int i;
	if(a[*count]>a[*count+1]){
		i=a[*count];
		a[*count]=a[*count+1];
		a[*count+1]=i;
	}
//	if(k*

//	r[*count]=0;
//	for(i=0;i<n;i++){
//		r[*count]=r[*count]+a[(*count)*n+i]*v[i];
//	}
	return NULL;
//	printf("%d\n",r[*count]);
}
int main(){
	int i,oddoreven,j;
 	printf("Enter size\n");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));

	printf("Enter value in array \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
        
	pthread_t thread[n/2];
	int *k;
	int temp;
	for(i=0;i<n;i++){
		
		oddoreven=(i%2==0)?1:0;
		temp=oddoreven;
//		k=&temp;
//		printf("iloop%d\n",temp);
		for(j=temp;j<n-1;j=j+2){	
			k=&j;	
			printf("lopp%d\n",*k);
			pthread_create(&thread[j/2],NULL,matvec,(void*)k);
			pthread_join(thread[j/2],NULL);
		}
        //        printf("end%d",i);

	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}


}


