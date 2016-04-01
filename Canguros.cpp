#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
queue <int> canguros;
string resultado="";
queue <int> re;
int main(){
optimizar_io;
char comando[2];
int c,d,n,Mi;
cin >> c >> n;
    while(n>0){
  cin >> comando;
     if(comando[0]=='N'){//Formamos a los canguros
            cin >> Mi;
       canguros.push(Mi);
     } else if(comando[0]=='A'){
      c = (c - canguros.front())-1; //Restamos la comida
       canguros.pop(); //vaciamos
     } else if(comando[0]=='C'){
       re.push(canguros.size());
         //Cantidad de canguros
     } else if(comando[0]=='R'){
         re.push(c);
     }
      n--;
    }//while
while(!re.empty()){
 cout << re.front()<<"\n";
 re.pop();
}
    return 0;
}
