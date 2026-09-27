
original_string = "Federal Bureau of Investigation"

ignore_list = ["a", "for", "an", "and", "by", "of"]

def build_acronym(original_string, ignore_list):

    splitted_array = original_string.split()

    # print(splitted_array)

    acronym = ""

    for index, element in enumerate(splitted_array):
        if index == 0 or element.lower() not in ignore_list:
            acronym += element[0].upper()

    return acronym


acronym_result = build_acronym(original_string, ignore_list)

print(acronym_result)