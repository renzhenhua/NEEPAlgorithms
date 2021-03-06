/**
* 2-路归排序的递归写法
**/


//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间（此处L2即为R1+1）
void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2; //i指向A[L1]，j指向B[L2]
    int temp[100], index = 0; //temp临时存放合并后的数组，index为其下标
    while (i <= R1 && j <= R2) {
        if (A[i] <= A[j])
            temp[index++] = A[i++]; //如果A[i]<=A[j]，将A[i]加入序列temp
        else
            temp[index++] = A[j++]; //如果A[i]>A[j]，将A[j]加入序列temp
    }
    while (i <= R1)
        temp[index++] = A[i++]; //将[L1,R1]的剩余元素加入序列temp
    while (j <= R2)
        temp[index++] = A[j++]; //将[[L2,R2]的剩余元素加入序列temp
    for (int i = 0; i < index; i++)
        A[L1 + i] = temp[i]; //将合并后的序列赋值回数组A
}

//将array数组当前区间[left,right]进行归并排序
void mergeSort(int A[], int left, int right) {
    //只要left小于right
    if (left < right) {
        int mid = (left + right) / 2; //取[left,right]的中点
        mergeSort(A, left, mid); //递归，将左子区间[left,mid]归并排序
        mergeSort(A, mid + 1, right); //递归，将右子区间[mid+1,right]归并排序
        merge(A, left, right, mid + 1, right); //将左子区间和右子区间合并
    }
}
