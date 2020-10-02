//implemented by denso -- 2020

int max_value(int *a, int size){
    int max = a[0];

    for(int i = 0;i<size;i++) if(a[i]>max) max = a[i];

    return max;
}

void countSort(int *a, int size, int exp){
    //array respuesta
    int ordered[size];
    int i, count[10] = {0};

    //conteo de cantidad de numeros del 0-9
    for (i = 0; i < size; i++) count[(a[i] / exp) % 10]++;
 
    //modificación de contadores
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
 
    //acomodo correcto en output
    for (i = size - 1; i>=0; i--) {
        ordered[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp) % 10]--;
    }
    
    //asignación de valores correctos en arreglo padre
    for (i = 0; i < size; i++) a[i] = ordered[i];
}

void radixSort(int *a, int size){
    //busqueda de mayor numero, para ver que tantos digitos tiene y iterar en ellos
    int m = max_value(a, size);

    //ordenamos el arreglo, con countSort, la cantidad de digitos que tenga el mayor numero {5555:4 digitos:4 veces}
    for (int digit = 1; (m/digit) > 0; digit *= 10)
        countSort(a, size, digit);
}
