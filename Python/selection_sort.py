
array = [9,3,4,1,2] # This is the default array 

print(array)

def selection_sort(array):
    # Here we iterate throught all the values on the array
    for i in range(0, len(array) - 1):
        # We declare a minimun index 
        min_index = i
         # Here we iterate all the values of the array going one a head of the first loop
        for j in range(i+1, len(array)):
            # If we found a numbers that is less than the minimum index, we saved it
            if array[j] < array[min_index]:
                min_index = j
        # Finally if the minimum index is different of 'i' wich is the first iteration, we swap them
        if min_index != i:
            array[i], array[min_index] = array[min_index], array[i]

    return array

print(selection_sort(array)) # This is the sorted array 