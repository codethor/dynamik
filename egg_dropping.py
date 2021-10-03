import sys
def eggdrop(n,k):
	# n = no of eggs
	# k = no of floors

	eggfloor = [[0 for i in range(k+1)] for j in range(n+1)]

	for j in range(1,k+1):
		eggfloor[1][j] = j

	for i in range(1,n+1):
		eggfloor[i][0] = 0
		eggfloor[i][1] = 1

	for i in range(2,n+1):
		for j in range(2,k+1):
			eggfloor[i][j] = sys.maxsize
			for x in range(1,j+1):
				res = max(eggfloor[i-1][x-1],eggfloor[i][j-x]) + 1
				if res < eggfloor[i][j]:
					eggfloor[i][j] = res

	for row in eggfloor:
		print(row)
	return eggfloor[n][k]

print(sys.maxsize)
print(eggdrop(2,100))

