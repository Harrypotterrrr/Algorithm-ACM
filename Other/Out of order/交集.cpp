#include <stdio.h>  
#include <stdlib.h>  
//#define M 8  
//#define N 5  
//int cmp(const void *a, const void *b)  
//{  
//    int *x = (int *)a;  
//    int *y = (int *)b;  
//    return (*x) - (*y);  
//}  
//  
//int main(void)  
//{  
//    int A[] = {-1, 2 ,39 ,10, 6, 11, 188, 10};  
//    int B[] = {39 ,8 , 10, 6, -1};  
//    //对数组A和数组B进行快排  
//    qsort(A, M, sizeof(int), cmp);  
//    qsort(B, N, sizeof(int), cmp);  
//    //FindIntersection(A, B);  
//    int i = 0, j = 0;  
//    int cnt = 0;  
//    int result[M > N ? M : N];//保存集合的结果  
//    //设置i、j索引，分别指向数组A和B，相等则同时移动，不相等则移动较小值的索引  
//    while(i < M && j < N)  
//    {  
//        if(A[i] == B[j])  
//        {  
//            result[cnt] = A[i];  
//            i++;  
//            j++;  
//            cnt++;  
//        }
//        else if(A[i] < B[j])  
//        {  
//            i++;
//        }  
//        else  
//        {  
//            j++;  
//        }  
//    }  
//    for(i = 0; i < cnt; i++)  
//    {
//        printf("%4d", result[i]);  
//    }
//    return 0;
//}
/* 
    Tencent: A、B两个整数集合，设计一个算法求他们的交集，尽可能的高效 
*/  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#define M 6  
#define N 5  
int Mymin(int a, int b)  
{  
    return a < b ? a : b;  
}  
int main(void)  
{  
    int A[] = {1, 10, 12, 23, 5, 45};  
    int B[] = {1, 10, 12, 123, 52};  
  
    //find MaxNumber in A  
    int ifindA = 0;  
    int MaxInA = A[0];  
    for(ifindA = 0; ifindA < M; ifindA++)  
    {  
        MaxInA = MaxInA > A[ifindA] ? MaxInA : A[ifindA];  
    }  
    //find MaxNumber in B  
    int ifindB = 0;  
    int MaxInB = 0;  
    for(ifindB = 0; ifindB < M; ifindB++)  
    {  
        MaxInB = MaxInB > B[ifindB] ? MaxInB : B[ifindB];  
    }  
  
    int *AsubPositive = (int *)malloc(sizeof(int) * (MaxInA + 1));  
    int *BsubPositive = (int *)malloc(sizeof(int) * (MaxInB + 1));  
    memset(AsubPositive, 0, sizeof(int) * (MaxInA + 1));  
    memset(BsubPositive, 0, sizeof(int) * (MaxInB + 1));  

    //COPY Positive and Negative numbers of A
    int i = 0;
    for(i = 0; i < M; i++)
    {
        AsubPositive[A[i]]++;
    }  
    //COPY Positive and Negative numbers of B
    int j = 0;
    for(j = 0; j < N; j++)
    {  
        BsubPositive[B[j]]++;
    }
    int icount = 0;
    //扫描AsubNegative和BsubPositive
    printf("the Intersection of A and B is : { ");
    for(int k = 0; k < M; k++)
    {
        //有交集输出该数
        icount = Mymin(AsubPositive[A[k]], BsubPositive[A[k]]);
        if(icount == 1)
        {
            printf("%-3d",A[k]);
        }
        A[k] = 0;
    }
    printf(" }");
    return 0;  
}  
