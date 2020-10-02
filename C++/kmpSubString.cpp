//implemented by denso -- 2020
#include <string>

int kmpSubString(std::string father, std::string pattern) {

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