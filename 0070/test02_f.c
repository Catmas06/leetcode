/*
    改进
        放弃递归，每次不再进行全部运算
        倒着来看，若第i层共n种走法，第i-1层共有m种走法
        则第i+1层开始走时，要么跳到第i层（1步），要么第i+1层（2步）
        因此i+1层共有 m+n 种走法
        正着来看，所要爬的层数i每+1，就要加上 i 层与 i-1 层的可能性
*/

int climbStairs(int n)
{
    int ret = 1;
    int temp1 = 1, temp2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            continue;
        }
        else
        {
            ret = temp1 + temp2;
            temp1 = temp2;
            temp2 = ret;
        }
    }
    return ret;
}