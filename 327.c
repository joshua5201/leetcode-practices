/* 327. Count of Range Sum
 * link: https://leetcode.com/problems/count-of-range-sum/description/
 * status: ac
 * 2018.9.22
 */


long long int merge(long long int *sums, int left, int mid, int right, int lower, int upper)
{
    /* find crs */
    int ll;
    int rl = mid, rr = mid;
    int res = 0;

    for (ll = left; ll < mid; ll++) {
        while (rl < right && (sums[rl] - sums[ll]) < lower) {
            rl++;
        }
        while (rr < right && (sums[rr] - sums[ll]) <= upper) {
            rr++;
        }
        res += (rr - rl);
    }

    /* sort */ 
    long long int tmp[right - left];
    int tmp_size = 0;
    ll = left;
    rr = mid;
    while (ll < mid && rr < right) {
        if (sums[ll] < sums[rr]) {
            tmp[tmp_size++] = sums[ll++]; 
        } else {
            tmp[tmp_size++] = sums[rr++];
        }
    }
    while (ll < mid) {
        tmp[tmp_size++] = sums[ll++]; 
    }
    while (rr < right) {
        tmp[tmp_size++] = sums[rr++];
    }
    for (int i = left; i < right; i++) {
        sums[i] = tmp[i - left];
    }

    return res;
}
long long int crs_by_merge_sort(long long int *sums, int left, int right, int lower, int upper)
{
    if (right - left <= 0) {
        return 0;
    }
    if (right - left == 1) {
        if (sums[left] <= upper && sums[left] >= lower) {
            return 1;
        } else {
            return 0;
        }
    }
    int mid = (left + right) / 2;
    long long int l_ans = crs_by_merge_sort(sums, left, mid, lower, upper);
    long long int r_ans = crs_by_merge_sort(sums, mid, right, lower, upper);

    return merge(sums, left, mid, right, lower, upper) + l_ans + r_ans;
}

int countRangeSum(int *nums, int num_size, int lower, int upper) 
{
    if (num_size == 0) {
        return 0;
    }
    long long int sums[num_size];
    sums[0] = nums[0];
    for (int i = 1; i < num_size; i++) {
        sums[i] = nums[i] + sums[i - 1];
    }
    
    return crs_by_merge_sort(sums, 0, num_size, lower, upper);
}
