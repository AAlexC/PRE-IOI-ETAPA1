#include <bits/stdc++.h>

using namespace std;

int nPos(int x, int limite){
	int r=x;
	int signo = x;
	x = abs(x);
	if(signo<0){
	r = limite - x;
	return r;
	} else if(signo > limite-1){
	return signo - limite;
	}
	else {
	return r;
	}
}

int betiPos(int x, int limite){
	int signo= x, resultado = signo;
	x = abs(x);
	if(x >= limite)    resultado = (x%limite);
	if(signo < 0){
 	if(resultado>0)  return resultado*-1;//Regresamos como quitando
 	else return resultado;
	} else {
	return resultado;
	}
}

int main(){
queue <int> guarda;
int n, m,k;
int c=0;
int MasI=0;
int MasJ=0;
cin >> n >> m >> k;
int Temp;
while(c < k){
 cin >> Temp;
if(Temp == 1) MasI--;
 else if(Temp == 2) MasI++;
  else if(Temp==3) MasJ--;
    else if(Temp==4) MasJ++;
c++;
}
    int tabla[n][m];
    int nueva[n][m];
    int F = betiPos(MasI, n);
    int C = betiPos(MasJ, m);

    for(int i=0;i < n;i++)
        for(int j=0; j<m;j++)
            cin >> tabla[i][j];

int p, pc;
    for(int i=0;i < n;i++){
        for(int j=0; j<m;j++){
        p = nPos(i+F, n);
        pc = nPos(j+C, m);
        nueva[p][pc]= tabla[i][j];
    	}
    }
   for(int i=0;i<n;i++){
   	for(int j=0;j<m;j++){
    printf("%d ", nueva[i][j]);
    }
 	printf("\n");
   }
    return 0;
}
