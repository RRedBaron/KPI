string = input().split()
maxlength = 0
maxword = minword = ""
for i in string:
    if len(i) > maxlength:
        maxlength = len(i)
        maxword = i
minlength = maxlength
for i in string:
    if len(i) < minlength:
        minlength = len(i)
        minword = i
string[string.index(maxword)] = minword
string[string.index(minword)] = maxword
print(' '.join(string))