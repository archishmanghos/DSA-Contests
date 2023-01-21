def MathChallenge(num):
	answer = num * (num + 1) // 2
	temp = str(answer)
	finalAnswer = ""
	for c in temp:
		if (c == '1' or c == '6' or c == '0' or c == '7'):
			finalAnswer += "--"
			finalAnswer += c
			finalAnswer += "--"
		else:
			finalAnswer += c

	return finalAnswer