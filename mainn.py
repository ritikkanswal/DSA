#ask user to input list
seq1 = list(map(float, input("sequence-1 input: ").split()))
seq2= list(map(float, input("sequence-2 input: ").split()))
seq1.pop()
seq2.pop()

res = []
i, j = 0, 0

#add two sorted list using while loop
while i < len(seq1) and j < len(seq2):
	if seq1[i] < seq2[j]:
	    res.append(seq1[i])
	    i += 1
	else:
	    res.append(seq2[j])
	    j += 1

res = res + seq1[i:] + seq2[j:]

for i in res:
    if(i.is_integer()):
        print(int(i),end=' ')
    else:
        print(i,end=' ')
