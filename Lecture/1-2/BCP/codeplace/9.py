vowels = ['a','e','o','i','u']
my_strings = input()
result = ''
for i in range(len(my_strings)):
	if my_strings[i] not in vowels:
		result += my_strings[i]
print(result)