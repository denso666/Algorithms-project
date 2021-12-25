
array = [9,3,4,1,2] # This is the default array 

print(array)

def bubble_sort(array):
    # Here we iterate throught all the values on the array
    for i in range(0, len(array) - 1):
        # Here we're going to iterate only throught all the numbers on the left of 'i'
        for j in range(0, len(array) - 1 - i):
            # If the first numbers appers to the greater than the second one, we swap them
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    
    return array

print(bubble_sort(array)) # This is the sorted array