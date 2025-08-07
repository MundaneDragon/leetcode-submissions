/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int start = 0;
    int* answer = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = start;i < numsSize;i++) {
        for(int j = start+1;j < numsSize;j++) {
            if ((nums[i] + nums[j]) == target) {
                answer[0] = i;
                answer[1] = j;
                return answer;
            }
        }
        start++;
    }

    return answer;
}