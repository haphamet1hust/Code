def findsum(arr,target):
	low = 0
	high = len(arr)-1
	while low < high:
		if arr[low] + arr[high] == target:
			print("Pair found",(arr[low],arr[high]))
			return
		elif arr[low] + arr[high] < target:
			low += 1
		else:
		  	high -= 1
	print("Not find pair correct")
lst = [2,4,5,8,10,12]
n = int(input())
findsum(lst,n)		  	

