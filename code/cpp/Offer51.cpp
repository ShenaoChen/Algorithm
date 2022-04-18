class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int num = 0;
        int n = nums.size();
        int *tmp = new int[n];
        mergeSort(nums, tmp, 0, n - 1, num);
        delete []tmp;
        return num;
    }
    void mergeSort(vector<int> &a, int tmp[], int l, int r, int &num){
        if(l >= r)
            return;
        int mid = l + r >> 1;
        int cnt = 0;
        int i = l, j = mid + 1;
        mergeSort(a, tmp, l, mid, num);
        mergeSort(a, tmp, mid + 1, r, num);
        while(i <= mid && j <= r){
            if(a[i] <= a[j])
                tmp[cnt++] = a[i++];
            else{
                tmp[cnt++] = a[j++];
                num += mid - i + 1;
            }
        }
        while(i <= mid) tmp[cnt++] = a[i++];
        while(j <= r) tmp[cnt++] = a[j++];
        for(i = l, j = 0; i <= r; i++, j++)
            a[i] = tmp[j];   
    }
};
