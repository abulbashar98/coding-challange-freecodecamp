ipv4_address = "255.01.50.111";

def is_valid_ipv4(ipv4_address):

    splitted_array_by_dot = ipv4_address.split(".")
    print(splitted_array_by_dot)

    if not splitted_array_by_dot:
        return False

    element_count = 0

    for index, element in enumerate(splitted_array_by_dot):

        # print("element: ", element)

        if len(element) > 1 and element[0] == '0':
            return False
        
        elif element == "":
            return False
        
        for char in element:
            if char < '0' or char > '9':
                return False

        element = int(element)

        if element < 0 or element > 255:
            return False         

        element_count += 1

    
    if element_count != 4:
            return False

    return True 

print(is_valid_ipv4(ipv4_address))