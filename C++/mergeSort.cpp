//implemented by denso

void merge(int *a, int left, int middle, int right){
    int i, j, k;
    int size = right - left + 1;//tamaño de todo el arreglo
    int sizeL = middle - left + 1;//tamaño de lado izquierdo
    int sizeR = size - sizeL;//tamaño de lado derecho

    int L[sizeL], R[sizeR];//arreglos temporales

    //copia de arreglo a arreglo temporal [lado izquierdo]
    for(i = 0; i<sizeL; i++)
        L[i] = a[left + i];
    //copia de arreglo a arreglo temporal [lado derecho]
    for(i = 0; i<sizeR; i++)
        R[i] = a[middle + 1 + i];

    //indices de arreglos temporales [i:izquierdo, j:derecho, k:arreglo original]
    i = 0, j = 0, k = left;

    //ciclo para ordenar todo los elemetos [size:tamaño del arreglo]
    for(int z = 0; z < size; z++){
        //se acabarón los elementos de L, solo quedan de R
        if(i == sizeL)
            a[k++] = R[j++];

        //se acabarón los elementos de R, solo quedan de L
        else if(j == sizeR)
            a[k++] = L[i++];

        //Aún se pueden comparar elmentos de ambos arreglos
        else{
            if(L[i] <= R[j]) a[k++] = L[i++];//elemento en L es menor que en R
            else a[k++] = R[j++];//elemento en R es menor que en L
        }
    }

}

//nota: en la primera llamada size es el tamaño del arrelo menos 1
void mergeSort(int *a, int left, int right){
    //el arreglo tiene más de un elemento
    if(left < right){
        int middle = left + (right - left) / 2;//indice para partir los arreglos

        mergeSort(a, left, middle);//paso recursivo a la mitad izquierda
        mergeSort(a, middle + 1, right);//paso recursivo a la mitad derecha 

        merge(a,left, middle, right);//mezcla de los arreglo ya ordenados
    }
}
