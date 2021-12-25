
array = [9,3,4,1,2] # This is the default array 

def get_pivot(array, lowest, highest):

    # We calculate the middle of the array
    middle = (highest - lowest) // 2
    # We use the highest number as the pivot
    pivot = highest
    # We search for the best pivot 
    if array[lowest] < array[middle]:
        if array[middle] < array[highest]:
            pivot = middle
    elif array[lowest] < array[highest]:
        pivot = lowest
    
    return pivot

def partition(array, lowest, highest):
    # We get the pivot
    pivot_index = get_pivot(array, lowest, highest)
    # We get the pivot value, wich we're using to each comparation
    pivot_value = array[pivot_index]

    # We swap the pivot value to the most left position on our array
    array[pivot_index], array[lowest] = array[lowest], array[pivot_index]

    # We set a border to the lowest item on the array
    border = lowest

    # We iterate throught our array from the low to the highest value + 1
    for i in range(lowest, highest + 1):
        if array[i] < pivot_value:
            # Everytime we move a number to the left, we move our border to the right
            border += 1
            # If the number is less than the pivot value we swap it with our border value
            array[i], array[border] = array[border], array[i]
    # When we're finish with the iteration, we're going to swap the lowest value wich is our pivot with the border
    array[lowest], array[border] = array[border], array[lowest]

    return (border)

def quick_sort(array, lowest, highest):
    if lowest < highest:
        pivot = partition(array,lowest,highest)
        # Using recursion to the left part of the array
        quick_sort(array, lowest, pivot - 1)
        # Using recursion to the right part of the array
        quick_sort(array, pivot + 1, highest)

quick_sort(array, 0, len(array) - 1)

print(array)