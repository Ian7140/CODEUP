#include<stdio.h>
int main(){
  int time,t;
  int a,b,c;
  scanf("%d",&time);
  t = time;
  a = t/300;
  t%=300;
  b = t/60;
  t%=60;
  c = t/10;
  t%=10;
  if(t!=0) printf("-1");
  else printf("%d %d %d",a,b,c);
  return 0;
}
