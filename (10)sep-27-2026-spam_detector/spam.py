
number = "+00 (358) 234-0182"

def isSpam(number):

    countryCode = number[1:number.index(" ")]
    areaCode = number[number.index("(") + 1 : number.index(")")]
    localNumber = number[number.index(")") + 2:].replace("-","")

    # check 1st condition

    if len(countryCode) > 2 or countryCode[0] != "0":
        return True;

    # check second condition
    areaInt = int(areaCode)

    if areaInt < 200 or areaInt > 900:
        return True

    #check 3rd condition

    sum_of_first_three_digits_in_local = int(localNumber[0])+int(localNumber[1])+int(localNumber[2])

    last_four_digits_in_local = localNumber[3:]

    if str(sum_of_first_three_digits_in_local) in last_four_digits_in_local:
        return True

    # check fourth condition

    digits = ""

    for char in number:
        if char.isdigit():
            digits += char


    count = 1
    for i in range(1, len(digits)):
        if digits[i] == digits[i-1]:
            count += 1
            if count >= 4:
                return True
        else:
            count = 1


    # return false if none of the condition is matching
    return False
     

if isSpam(number):
    print("The given number is a spam")

else:
    print("The number is valid")