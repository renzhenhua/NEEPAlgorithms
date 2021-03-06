/**
* 时间复杂度为O(sqrt(n))的素数判断
* 思路：如果在2 - n-1中存在n的约数，不妨设为k，即n%k==0，
*       那么由k*(n/k)==n可知，n/k也是n的一个约数
*       且k与n/k中一定满足其中一个小于等于sqrt(n)，另一个大于等于sqet(n)
*       则只需要判定n能否被2，3，...，⌊sqrt(n)⌋中的一个整除（⌊x⌋表示对x向下取整），即可判定n是否为素数
**/

//code
bool isPrime(int n) {
    if (n <= 1)
        return false; //特判
    int sqr = (int)sqrt(1.0 * n); //根号n
    //遍历2-根号n
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false; //n是i的倍数，则n不是素数
    }
    return true;
}

//simple code
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
