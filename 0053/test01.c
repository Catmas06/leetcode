/*
    53. 最大子数组和
        给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
        子数组 是数组中的一个连续部分。
    思想
        - 从前向后遍历，记录当前加和、历史最大值
        - 历史最大值从第一次加和算起，取最大值
        - 当前加和小于0时，放弃已有加和，下一轮开始重新计算
*/

//  过于复杂
// int maxSubArray(int *nums, int numsSize)
// {
//     //将初始值设置为nums[0]，之后从nums[1]开始判断
//     int maxNum = nums[0], curNum = nums[0], i = 0;
//     while (i < numsSize)
//     {
//         //当前加和不小于0，则一直向后累加
//         while (i < numsSize - 1 && curNum > 0)
//         {
//             i++;
//             curNum += nums[i];
//             //每次加和完成都判断是否刷新最大值
//             maxNum = curNum > maxNum ? curNum : maxNum;
//         }
//         //当指向最后一个元素时，要么在上面的循环中已判断完毕，要么在上一轮循环末尾已判断完毕，因此不需要额外判断
//         if (i == numsSize - 1)
//         {
//             break;
//         }
//         i++;
//         curNum = nums[i];
//         maxNum = curNum > maxNum ? curNum : maxNum;
//     }
//     return maxNum;
// }

//每次给cur赋值后都要判断是否需要更新max
int maxSubArray(int *nums, int numsSize)
{
    int max = nums[0];
    for (int i = 0; i < numsSize;)
    {
        int cur = nums[i++];
        max = cur > max ? cur : max;
        while (i < numsSize && cur > 0)
        {
            cur += nums[i];
            max = cur > max ? cur : max;
            i++;
        }
    }
    return max;
}

int main()
{
    int nums[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(nums, 9);
    return 0;
}