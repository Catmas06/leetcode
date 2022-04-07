/*
    198. 打家劫舍
        你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
        给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
    思想
        - 动态规划，计算出：若对当前房子下手，所能得到的最高金额，最后对比末尾两个最高金额，则得到总共可得的最高金额
*/

int rob(int *nums, int numsSize)
{
    if (numsSize < 2)
    {
        return nums[0];
    }
    if (numsSize < 3)
    {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    if (numsSize == 3)
    {
        return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
    }
    int pre2Max = nums[0], pre1Max = nums[1], preMax = nums[2] + nums[0];
    int curMax, i = 3;
    while (i < numsSize)
    {
        curMax = pre2Max + nums[i] > pre1Max + nums[i] ? pre2Max + nums[i] : pre1Max + nums[i];
        pre2Max = pre1Max;
        pre1Max = preMax;
        preMax = curMax;
        i++;
    }
    return preMax > curMax ? preMax : curMax;
}