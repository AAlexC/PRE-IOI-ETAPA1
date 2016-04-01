#include <bits/stdc++.h>
using namespace std;

int main(){
int tp;
int salva;
 scanf("%d", &tp);
salva=tp;
int to=0;
char ca[2];
int ya=0;
ca[1]='0';
    while(tp>0){
  cin >> ca[0];
    if(ya>0 && ca[0]!=ca[1]){
     to++;
         if(ca[0]=='W') ca[0]='B';
            else ca[0]='W';
    }
        if(ca[0]=='W') ca[1]='B';
            else ca[1]='W';
    ya++;
    tp--;
}
cout <<  min(to, salva - to) <<"\n";
    return 0;
}
