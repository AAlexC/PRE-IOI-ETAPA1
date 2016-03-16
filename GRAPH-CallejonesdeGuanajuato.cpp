#include "callejones.h"
#include <bits/stdc++.h>

using namespace std;

stack<int> esq;
vector<int>so;
vector<int>vecinos[1010];
vector<int>::iterator borde;
int totalV[1100];
int grados[1100];
int vPar=0, vImpar=0, iImpar, iPar, totalAristas;

void programa(int esquinas, int callejones, int matriz[][1000]) {

   for(int i=0;i<esquinas;i++){

    for(int j=0;j<esquinas;j++){
            if(matriz[i][j]==1){
            grados[i]++;
            totalAristas++;
            vecinos[i].push_back(j);
            totalV[i]++;
            }
    }
                    if(grados[i]%2==0){
                    vPar++;
                    iPar=i;
                    }else{
                    vImpar++;
                    iImpar=i;
                    }
    }
int A,B;
if(vPar<esquinas){
        if(vImpar!=2){
                imposible();//Imposible XD
            return;
        }
A = iImpar;
while(totalAristas>0){
        if(vecinos[A].size()>0){
            esq.push(A);
        B=vecinos[A].front(); vecinos[A].erase(vecinos[A].begin());
        borde = upper_bound(vecinos[B].begin(), vecinos[B].end(), A);
        int pos= (borde-vecinos[B].begin())-1;
        vecinos[B].erase(vecinos[B].begin()+pos);
        A = B;
        } else {//Metemos a circulo de solución
         so.push_back(A);
         if(esq.empty()) break;
         A=esq.top(); esq.pop();
        }
}
} else { //Inicia con cualquiera
    A = iPar;
while(totalAristas>0){
        if(vecinos[A].size()>0){
            esq.push(A);
        B=vecinos[A].front();
        vecinos[A].erase(vecinos[A].begin());
        borde = upper_bound(vecinos[B].begin(), vecinos[B].end(), A);
        int pos= (borde-vecinos[B].begin())-1;
        vecinos[B].erase(vecinos[B].begin()+pos);
        A = B;
        } else {//Metemos a circulo de solución
         so.push_back(A);
         if(esq.empty()) break;
         A=esq.top(); esq.pop();
        }
}
}
for(int i=0;i<so.size();i++)avanza(so[i]);
    return;
}
