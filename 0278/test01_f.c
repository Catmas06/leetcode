/*
    278. 第一个错误的版本
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    long low = 1, high = n, mid = (low + high) / 2;
    while (low < high)
    {
        if (isBadVersion(mid))
        {
            high = mid;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    return low;
}