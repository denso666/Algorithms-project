
array = [9,3,4,1,2] # This is the default array 

print(array)

def insertion_sort(array):
    # Here we iterate throught all the values on the array
    for i in range(0,len(array)):
        # Here we're going to iterate only throught all the numbers on the left of 'i'
        for j in range(i - 1, -1, -1):
            # This is going to move the number all the way to his place on one go
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
            # When we're out of numbers we break this loop
            else:
                break
    
    return array

print(insertion_sort(array)) # This is the sorted array 