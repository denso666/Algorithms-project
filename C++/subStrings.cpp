//implemented by denso -- 2020
#include <string>
#include <map>
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

int boyerMooreSubString(string father, string son){
    int fatherLen = father.length();
    int sonLen = son.length();

    //Bad Match Table -- diccionario de valores posicionales de la sub cadena
    map<char,int> badMatch;

    //llenamos el diccionario con los caracteres y su valor correspondiente
    // donde su valor es la cantidad de movimientos que se haran si no concuerda el caracter pero si existe dentro de la subcadena
    for(int i = 0; i<sonLen; i++)
        badMatch[son[i]] = max(1,(sonLen - i -1));

    //fatherIndex: posicion en cadena padre, fatherTemp: posición de comparación en cadena padre
    int fatherIndex = sonLen - 1, fatherTemp;
    //sonIndex: posición en cadena hijo
    int sonIndex;

    //recorrido por la cadena padre
    while(fatherIndex < fatherLen){
        sonIndex = sonLen - 1;

        // concuerdan caracteres de cadenas
        if(father[fatherIndex] == son[sonIndex]){
            fatherTemp = fatherIndex;
            //verificación de que las subcadena concuerde
            while(father[fatherTemp] == son[sonIndex]){
                sonIndex--;
                if(sonIndex < 0) return fatherTemp; 
                fatherTemp--;
            }
        }

        //existe el caracter en la tabla de match aumentamos en la cantidad del caracter
        if(badMatch[father[fatherIndex]] != 0) fatherIndex += badMatch[father[fatherIndex]];
        //no existe el caracter, aumentamos el tamaño de la subcadena
        else fatherIndex += sonLen;
    }

    return -1;
}

int KMPSubString(string father, string pattern) {

    int fatherLen = father.length();
    int patternLen = pattern.length();
    //arreglo de valores de movimiento
    int lps[patternLen];

    //la primera letra del patron no cuenta como patron, por ende sera siempre 0
    lps[0] = 0;
    //i: posicion del patron, k: valor que se le asignara
    int i = 1, k = 0;
    
    //verifica si hay o no patrones y asigna su valor correspondiente
    while(i<patternLen){
        if(pattern[i] == pattern[k]) lps[i++] = ++k;
        else{
            if(k) k = lps[k-1];
            else lps[i++] = k;
        }
    }

    //i: posicion en cadena, k: posición en patron
    i = 0, k = 0;
    //comparación de cadena y patron
    while(i<fatherLen){
        //los caracteres concuerdan
        if(father[i] == pattern[k]) i++,k++;
        //los caracteres no concuerdan
        else{
            if(k) k = lps[k - 1];
            else i++;
        }
        //se encontro el patron
        if(k == patternLen) return i-k;
    }

    return -1;
}
