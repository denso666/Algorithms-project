//implemented by denso -- 2020
#include <string>
#include <map>
using namespace std;

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