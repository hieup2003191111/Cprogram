#include<stdio.h>
#include<stdlib.h>

int* sum(int* nums,int target,int size){
    int* result = (int*)malloc(2 * sizeof(int));
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    return NULL;
}
int main(){
    int size,target;
    printf("enter number of element array \n");
    scanf("%d",&size);
    printf("enter target \n");
    scanf("%d",&target);
    int* nums = (int*)malloc(size*sizeof(int));
    printf("enter elements of array \n");
    for(int i=0;i<size;i++){
        scanf("%d",&nums[i]);
    }
    int* result = sum(nums,target,size);
    printf("resutl = [%d,%d] \n",result[0],result[1]);
    free(result);
    free(nums);
    return 0; 
}