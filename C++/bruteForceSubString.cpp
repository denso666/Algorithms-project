//implemented by denso -- 2020
#include <string>
using namespace std;

int bruteForceSubString(string father, string son){
    int fatherLen = father.length();
    int sonLen = son.length();

    //comparación de la cadena padre y la cadena hijo, caracter por caracter
    for(int i = 0;i<(fatherLen-sonLen+1);i++){
        for(int j = 0;j<sonLen;j++){
            if(father[i+j] != son[j]) break;
            if(j == sonLen-1) return i;
        }
    }
    //no encontrado
    return -1;
}