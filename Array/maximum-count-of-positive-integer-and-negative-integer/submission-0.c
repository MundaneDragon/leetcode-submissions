int maximumCount(int* nums, int numsSize) {

    int count_pos = 0;
    int count_neg = 0;

    for (int i = 0; i < numsSize; i++ ) {
        if (nums[i] > 0) {
            count_pos++;
        } else if (nums[i] < 0) {
            count_neg++;
        }
    }

    if (count_pos > count_neg) {
        return count_pos;
    }

    return count_neg;
    
}