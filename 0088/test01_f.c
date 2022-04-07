/*
    88. 合并两个有序数组
        给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
        请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
        注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
    思想
        - 从后向前，每次选出最大值放入nums1中
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int temp = m + n;
    while (m && n && temp)
    {
        if (nums1[m - 1] > nums2[n - 1])
        {
            nums1[temp - 1] = nums1[m - 1];
            m--;
        }
        else
        {
            nums1[temp - 1] = nums2[n - 1];
            n--;
        }
        temp--;
    }
    if (n == 0 || temp == 0)
    {
        return;
    }
    else
    {
        while (n)
        {
            nums1[temp - 1] = nums2[n - 1];
            temp--;
            n--;
        }
        return;
    }
}

int main()
{
    int nums1[1] = {0};
    int nums2[1] = {1};
    merge(nums1, 1, 0, nums2, 1, 1);
    return 0;
}