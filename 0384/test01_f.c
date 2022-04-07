/*
    0384.Shuffle an Array
    Given an integer array nums, design an algorithm to randomly shuffle the array.
    All permutations of the array should be equally likely as a result of the shuffling.
    Implement the Solution class:
    Solution(int[] nums) Initializes the object with the integer array nums.
    int[] reset() Resets the array to its original configuration and returns it.
    int[] shuffle() Returns a random shuffling of the array.
*/

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/
#include <time.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int *copy;
    int *src;
} Solution;

Solution *solutionCreate(int *nums, int numsSize)
{
    Solution *s = (Solution *)malloc(sizeof(Solution));
    s->size = numsSize;
    s->src = nums;
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    s->copy = temp;
    for (int i = 0; i < numsSize; i++)
    {
        temp[i] = nums[i];
    }
    return s;
}

int *solutionReset(Solution *obj, int *retSize)
{
    *retSize = obj->size;
    return obj->src;
}

int *solutionShuffle(Solution *obj, int *retSize)
{
    *retSize = obj->size;
    // srand((unsigned)time(NULL));
    int temp1 = rand() % (*retSize), temp2;
    int tempNum = obj->copy[temp1];
    for (int i = 0; i < *retSize; i++)
    {
        // srand((unsigned)time(NULL));
        temp2 = rand() % (*retSize);
        tempNum = obj->copy[temp1];
        obj->copy[temp1] = obj->copy[temp2];
        temp1 = temp2;
    }
    obj->copy[temp2] = tempNum;
    return obj->copy;
}

void solutionFree(Solution *obj)
{
    free(obj);
}
