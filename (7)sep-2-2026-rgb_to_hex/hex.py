
rgb_string = "rgb(243, 177, 24)";

def convert_to_hex(rgbString):

    extractedValuesArrayFromString = rgb_string.replace("rgb(", "").replace(")", "").split(",")

    print(extractedValuesArrayFromString)

    r = int(extractedValuesArrayFromString[0])
    g = int(extractedValuesArrayFromString[1])
    b = int(extractedValuesArrayFromString[2])

    return "#" + \
           f"{r:02x}" + \
           f"{g:02x}" + \
           f"{b:02x}"


result = convert_to_hex(rgb_string)

print(result)