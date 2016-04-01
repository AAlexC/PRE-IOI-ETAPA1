#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

bool visitado[MAXN][MAXN][MAXN];
string room[MAXN][MAXN][MAXN];

struct Estado{
int x, y, z, d;
};
int N;

int regresa(char c){

if(c=='N') return 0;
else if(c=='S') return 1;
else if(c=='O') return 2;
else if(c=='E') return 3;
else if(c=='U') return 4;
else if(c=='D') return 5;

}

int tumama[6][4]{ {0,1,0},{0,-1,0},{-1,0,0},{1,0,0},{0,0,1},{0,0,-1}
};

int finX, finY, finZ, K;

int bfs(int iniX, int iniY,int iniZ){
       Estado inicio;

       inicio.x=iniX;
       inicio.y=iniY;
       inicio.z=iniZ;
       inicio.d=0;

        queue <Estado> Q;
       Q.push(inicio);

        while(!Q.empty()){

        Estado actual = Q.front();
        Q.pop();

        if(actual.x == finX && actual.y == finY && actual.z == finZ){
          return actual.d;

        }

if(actual.d >= 2*K) return -1;

if(visitado[actual.x][actual.y][actual.z]==true) continue;

     visitado[actual.x][actual.y][actual.z]=true;

              for(int i=0; i<room[actual.x][actual.y][actual.z].size(); i++){

                int xd = regresa(room[actual.x][actual.y][actual.z][i]);

                       int XX= tumama[xd][0]+actual.x;
                       int YY =tumama[xd][1]+actual.y;
                       int ZZ=tumama[xd][2]+actual.z;

                  if(XX >= 0 && YY >= 0 && ZZ >= 0 && XX < N && YY<N && ZZ<N){
                       Estado adyacente;
                       adyacente.x= XX;
                       adyacente.y=YY;
                       adyacente.z=ZZ;
                       adyacente.d= actual.d+1;

                     Q.push(adyacente);
                  }


              }// FOR _____________
 }
 
 return -1;
 }

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int i,j,ko;
    cin >> N >> K;
cin >> finX >> finY >> finZ;
 for(i=0;i<N;i++){
    for(j=0;j<N;j++){
     for(ko=0;ko<N;ko++){
            cin >> room[i][j][ko];
     }
    }
 }

int ans = bfs(0,0,0);

if(ans!=-1){
cout << ans/2;
if(ans%2==1) cout <<".5";
cout << "\n";
} else {
printf("Impossibru\n");
}
    return 0;
}
