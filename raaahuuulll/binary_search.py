# For Binary Search to work, the array needs to be sorted.

def binary_search(arr, key, low, high):
	mid = (low + high) / 2
	if arr[mid] == key:
		return mid
	elif arr[mid] < key:
		return binary_search(arr, key, low, mid)
	elif arr[mid] > key:
		return binary_search(arr, key, mid, high)

arr = [1, 3, 4, 5, 7, 10]
index = binary_search(arr, 4, 0, len(arr)-1) 
print("The value is present at", index)
