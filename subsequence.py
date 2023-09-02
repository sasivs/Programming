

def issubsequence(s1, s2):

	n, m = len(s1), len(s2)
	i, j = 0, 0
	while (i < n and j < m):
		if (s1[i] == s2[j] or chr(97+(ord(s2[j])+1)%97%26) == s1[i]):
			i += 1
		j += 1
	if i==n:
		return "YES"
	return "NO"

def checkSimilarPasswords(new_passwords, old_passwords):
	result = []
	for i in range(len(new_passwords)):
		result.append(issubsequence(old_passwords[i], new_passwords[i]))
	return result

s1 = "baacba"
s2 = "abb"
print(issubsequence(s2, s1))
