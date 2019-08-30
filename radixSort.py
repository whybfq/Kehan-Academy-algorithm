def radix_sort(to_be_sorted):
    maximum_value = max(to_be_sorted)
    max_exponent = len(str(maximum_value))

    being_sorted = to_be_sorted[:]
    digits = [[] for i in range(10)]
    for number in being_sorted:
        number_as_a_string = str(number)
    digit = int(str(number)[-1])

    digits[digit].append(number)
    return digits
