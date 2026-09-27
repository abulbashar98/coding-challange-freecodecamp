arr1 = ["I", "like", "freeCodeCamp"]
arr2 = ["I", "like", "rocks"]

def semantic_diff_in_alphabetical_order(arr1, arr2):
    
    result = sorted(set(arr1) ^ set(arr2)) 

    print(result)

semantic_diff_in_alphabetical_order(arr1, arr2)