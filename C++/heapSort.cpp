//implemented by denso

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int *a, int size, int i){ 
    //busqueda de el más largo de la raiz, el hijo izquierdo y derecho
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
  
    //hijo izquierdo es mayor que la raiz 
    if(left<size and a[left] > a[largest]) largest = left; 
  
    //hijo derecho es más grande que el más grande hasta ahora 
    if(right<size and a[right] > a[largest]) largest = right; 
  
    // comparación: la raíz es el más grande? 
    if (largest != i){ 
        swap(&a[i], &a[largest]); 
        // recursividad a subarboles 
        heapify(a, size, largest); 
    } 
} 
  
//nota: la primera llamada size es el tamaño real del arreglo
void heapSort(int *a, int size){
     
    //creación de max-heap {montón}
    for (int i = size/2-1; i>=0;i--) heapify(a, size, i); 
  
    // One by one extract an element from heap 
    for(int i=size-1; i>0; i--){ 
        //cambiamos la raíz con el actual en el arreglo
        swap(&a[0], &a[i]); 
  
        //recursividad para obtener el más alto siguiente de la raíz
        heapify(a, i, 0); 
    } 
} 
