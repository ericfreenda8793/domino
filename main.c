#include<stdio.h>
char b[3][22];
int count=0;
void countWays(int startr,int startc,int n)
{

    if(startc==n){

        count++;

    }

    if(b[startr][startc]=='0'){
        //2 ways to implement
  for(int i=0;i<2;i++){
  if(i==0){

  if(startr+1<3 && b[startr+1][startc]=='0'){
        //vertical
        b[startr+1][startc]=b[startr][startc]='1';
       countWays(startr+1,startc,n);
       b[startr+1][startc]=b[startr][startc]='0';

  }
  }
  else if(i==1){
    if(startc+1<n && b[startr][startc+1]=='0'){
        //horizontal
        b[startr][startc+1]=b[startr][startc]='1';
        if(startr+1!=3){
         countWays(startr+1,startc,n);
        }
        else{
            countWays(0,startc+1,n);
        }
        b[startr][startc+1]=b[startr][startc]='0';

    }
  }


   }
    }else if(b[startr][startc]=='1'){
    if(startr==2){
       countWays(0,startc+1,n);
    }
    else{
      countWays(startr+1,startc,n);
    }

    }




}
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        b[1][i]=b[2][i]=b[0][i]='0';
    }
   countWays(0,0,n);
printf("%d\n",count);
    return 0;
}
