
def countKAverageSubarrays(arr, k):
	iter_sum = 0
	count = 0
	freq = {}
	for i in arr:
		iter_sum += i-k

		if iter_sum == 0:
			count+=1

		if iter_sum in freq.keys():
			count+=freq[iter_sum]
			freq[iter_sum] += 1
		else:
			freq[iter_sum] = 1
	return count

def main():
	print(countKAverageSubarrays([1,2,3,4], 2))


if __name__ == '__main__':
	main()