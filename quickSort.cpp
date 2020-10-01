//implemented by denso

///////////////////////////Intercambio de valores entre dos punteros
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

///////////////////////////Preacomodo de una sección (menores < pivote < mayores)
int partition (int *a, int left, int right){ 
    // valor del pivote //en el caso particular tomamos como pivote el número al extremo derecho de la lista
    int pivot = a[right];
    
    // indice de elementos menores que el pivote  
    int i = (left - 1); 

    //ciclo para selección y cambio de menores que pivote
    for (int j = left; j<=right-1; j++)
        //intercambio y aumento de indice de menores
        if (a[j] <= pivot) swap(&a[++i], &a[j]);
    
    // intercambio de pivote a la posición correspondiente
    swap(&a[i + 1], &a[right]);

    //retorno de posición donde quedo el pivote
    return (i + 1); 
}

//nota: en la primera llamada size es el tamaño del arrelo menos 1
void quickSort(int *a, int left, int right){
    if (left < right){
        //obtención de un pivote (menores < pivote < mayores) para posterior división
        int pivot = partition(a, left, right); 
   
        //división del problema
        quickSort(a, left, pivot - 1); //menores que pivote
        quickSort(a, pivot + 1, right); //mayores que pivote 
    } 
}