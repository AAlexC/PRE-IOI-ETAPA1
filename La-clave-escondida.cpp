#include <bits/stdc++.h>
using namespace std;
char retornaLetra(int x){
char letra = (char)x;
return letra;
}
int valorLetra(char letra){
int valor = letra;
if(valor >= 97) return valor-96;
else return valor-64;
}
    int Decifra(int n1, string cadena1){
    int partes = cadena1.size()/n1;
    int comienza;
    int valor;
    int pos;
    int fin=1;
        for(int i=0; i < n1; i++){
             comienza = i;
             pos = (i+n1); // posicion siguiente para sumarle
            valor=valorLetra(cadena1[i]);
             for(int j=0; j<(partes-1); j++){
                  valor += valorLetra(cadena1[pos]);
            pos += n1;
             }
           valor = (valor%10)+1;
             fin = (fin*(valor))%10;
        }
        return fin;
    }
    int main(){
  string cadena1="";
  string cadena2="";
    int n1;
    int n2;
    char basura[1]; // Valor de !
    cin >> basura[0];
    cin >> n1;
    cin >> cadena1; //Cadena para obtener el entero
    cin >> basura[0];
    cin >> n2;
    cin >> cadena2; //Cadena para obtener el entero
     int res1 = (Decifra(n1, cadena1) % 10)+1;
     int res2 = (Decifra(n2, cadena2) % 10)+1;
        char respuesta[3];
 cout << res1 << "-" << retornaLetra(res2+64)<<"\n";
    return 0;
    }
