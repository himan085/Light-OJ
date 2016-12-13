int a, b, c, d, e, f;

int fn( int n ) {int i;
long long int res[10001]={0};
    res[0]=a; res[1]=b; res[2]=c; res[3]=d; res[4]=e; res[5]=f;
   if(n==0 ||n==1 || n==2 ||n==3 || n==4 ||n==5  ) return res[n];
else {
for(i=6; i<=n; i++)
res[i]=((res[i-1]% 10000007)+(res[i-2]% 10000007)+(res[i-3]% 10000007)+(res[i-4]% 10000007)+(res[i-5]% 10000007)+(res[i-6]% 10000007))% 10000007;

return res[n];
}

}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
