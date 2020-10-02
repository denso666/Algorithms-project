//implemented by densos

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//nota: en la primera llamada size es el tamaño del arrelo menos 1
void selectionSort(int *a, int size)
{
    //indice temporal para intercambios posteriores
    int minor;

    //busqueda en arreglo desordenado
    for (int i = 0; i < size - 1; i++)
    {

        //indice i lo tomamos como nuestro elemento menor
        minor = i;

        //comparación de indice con todo el arreglo restante, buscando al menor
        for (int j = i + 1; j < size; j++)
            //indice menor que el actual comparado, se modifica indice de menor
            if (a[j] < a[minor])
                minor = j;

        //intercambio de valores // indice actual:i, indice del menor:minor
        swap(&a[i], &a[minor]);
    }
}