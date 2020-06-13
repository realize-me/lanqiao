/*
    问题描述
给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。

输入格式
第一行包含一个数n，表示序列长度。

第二行包含n个正整数，表示给定的序列。

第三个包含一个正整数m，表示询问个数。

接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。

输出格式
总共输出m行，每行一个数，表示询问的答案。
样例输入
5
1 2 3 4 5
2
1 5 2
2 3 2
样例输出
4
2
数据规模与约定
对于30%的数据，n,m<=100；

对于100%的数据，n,m<=1000；

保证k<=(r-l+1)，序列中的数<=106。
*/
#include<iostream>
using namespace std;
double arr[1000];
double brr[1000];
double temp;
int n;
int m;

void solve(int l,int r,int k)
{
    int size_brr = r - l + 1;
    for (int i = l; i <= r; i++){
        brr[i - l] = arr[i];
    }

    int max;
    for (int i = 0; i < size_brr; i++){
        max = i;
        for (int j = i+1; j < size_brr; j++){
            if(brr[j]>brr[max]){
                max = j;
            }
        }
        if(max != i){
            temp = brr[i];
            brr[i] = brr[max];
            brr[max] = temp;
        }
    }
    cout <<brr[k]<<endl;
}

int main (){
    int l, r, k;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> l >> r >> k;
        solve(l-1, r-1, k-1);
    }
    
    return 0;
}