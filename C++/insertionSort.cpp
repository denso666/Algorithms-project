//implemented by denso

//nota: en la primera llamada size es el tamaño del arrelo
void insertionSort(int *a, int size)
{
    //j: indice anterior para el cambio, key: valor que esta ordenandose
    int j, key;

    //recorremos todo el arreglo ordenando elemento por elemento
    for (int i = 1; i < size; i++)
    {
        //seleccionamos el elemento a ordenar
        key = a[i];

        //tomamos el primer predecesor de key para iniciar las comparaciones
        j = i - 1;

        //comparamos el valor key con sus predecesores y los movemos a la derecha de ser mayor que key
        while (j > -1 and a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        //ponemos el valor key en su lugar correspondiente
        a[j + 1] = key;
    }
}
