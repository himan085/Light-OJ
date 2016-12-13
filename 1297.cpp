#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
double l,w,x;
cin>>t;
for(int tc=1;tc<=t;tc++){
cin>>l>>w;
 x= ((w+l)-sqrt(w*w+l*l-w*l))/6;

 printf("Case %d: %lf\n",tc,(l-2*x)*(w-2*x)*x);

}

return 0;

}
