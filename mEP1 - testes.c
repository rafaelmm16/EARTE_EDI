// C++ program to print largest contiguous array sum
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a, n;
int ans = a[0], ans_l = 0, ans_r = 0;
int sum = 0, minus_pos = -1;

scanf("%d", &n);
a=(int*)malloc(n*sizeof(int*));

int k;
for (int i = 0; i < n; i++)
{
    scanf("%d", &a[i]);
}
scanf("%d", &k);

for (int r = 0; r < k; ++r) {
    sum += a[r];
    printf("%d\n", sum);
    if (sum > ans) {
        ans = sum;
        ans_l = minus_pos + 1;
        ans_r = r;
    }
    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
}
    printf("%d", sum);
    return 0;
}