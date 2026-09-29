arbitrary_str = "  ?H^3-1*1]0! W[0%R#1]D  "

def slug_generator(arbitrary_str):

    result = []

    lower_str = arbitrary_str.lower()
    
    previous_was_space = False

    for char in lower_str:
        if char.isalnum():
            result.append(char)
            previous_was_space = False

        if char == " ":
            if result and not previous_was_space:
                result.append("%20")
                previous_was_space = True

        # ignore all other characters

    if result and result[-1] == "%20":
        result.pop()

    return "".join(result) 


slug = slug_generator(arbitrary_str)
print(slug)