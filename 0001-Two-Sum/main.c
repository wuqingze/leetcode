/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int*) malloc(sizeof(int)*2);
    int *ptr = result;
    for(int i=0; i<numsSize; i++){
        for(int j=0; j<numsSize; j++){
            if(i != j && nums[i]+nums[j] == target){
                *ptr = i;
                *(++ptr) = j;
                *returnSize = 2;
                goto label;
            }
        }
    }
label:
    return result;
}
