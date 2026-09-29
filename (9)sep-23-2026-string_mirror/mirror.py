
str1 =  "!dlroW !olleH";
str2 = "Hello World";

def isMirror(str1, str2):

    final_str1 = ""
    final_str2 = ""

    for char in str1:
        if char.isalpha():
            final_str1 += char

    for char in str2:
        if char.isalpha():
            final_str2 += char

    return final_str1[::-1] == final_str2

print(isMirror(str1,str2))

