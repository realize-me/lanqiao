/*

问题描述
已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。

输入格式
输入一个正整数N。

输出格式
输出一个整数，表示你找到的最小公倍数。
样例输入
9
样例输出
504
数据规模与约定
1 <= N <= 106。



数学知识:如果三个数互为质数,那么这三个数的乘积便为它们的最小公倍数。

因为本题目中要求最小公倍数的最大值,那么可以直接从N向前看,找三个连续的互为质数的数,那么它们的乘积便是1~N最小公倍数的最大值。
有以下二种情况。
(1)、当N为奇数时,那么N,N-1,N-2互为质数,很明显N*N-1*N-2是1~N最小公倍数的最大值。
(2)、当N为偶数时,且能被3整除时,N-1,N-2,N-3互质,此时N-1*N-2*N-3是1~N最小公倍数的最大值；当N为偶数时,但不能被3整除时,N,N-1,N-3互质,此时N*N-1*N-3是1~N最小公倍数的最大值。
————————————————
版权声明：本文为CSDN博主「花开成景花落为诗」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/xiaofengcanyuelong/article/details/79271225
*/

#include<iostream>
using namespace std;
int n;
void solve(){
    double max = 0;
    if(n<=2){
        max = n;
        cout << max;
        return;
    }
    // 奇数
    if (n%2==1){
        max = n * (n - 1) * (n - 2);
        cout << max;
        return;
    }
    // 偶数且是3的倍数
    if(n%3==0){
        max = (n - 1) * (n - 2) * (n - 3);
    }else{
    //偶数不是3的倍数
        max = n * (n - 1) * (n - 3);
    }
    cout << max;
}
int main (){
    cin >> n;
    solve();
    return 0;
}