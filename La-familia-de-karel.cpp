#include <iostream>
#include <queue>
using namespace std;
#define MAXD 100010
int hijos[MAXD];
int memo[MAXD];
queue <int> gen;
int temporal,para;
 int recursiva(int x, int nivel){
 if(hijos[x]!=x){
     ++nivel;
  gen.push(nivel);
     recursiva(hijos[x], nivel);
     memo[x] = gen.front();
       temporal = gen.front();
     gen.pop();
  return temporal;
     } else {
     memo[x]=1;
     }
 }

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
int n;
cin >> n;
cin >> hijos[0];
for(int i=1;i<=n;i++) cin >> hijos[i];

int g,genera;

genera = recursiva(0,1);
int primos=0;
for(int i=1;i<=n;i++){
 if(memo[i]!=0){
if(memo[i]==genera) primos++;
    continue;
 }
    g=recursiva(i,1);
     memo[i]=g;
  if(memo[i]==genera) primos++;
}
  cout << primos<<"\n";
   return 0;
}
