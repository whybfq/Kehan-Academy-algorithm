[Radix Sort](https://www.codecademy.com/paths/computer-science/tracks/sorting-algorithms/modules/cs-radix-sort/lessons/radix-sort-python/exercises/rendering-the-list)


def radix_sort(to_be_sorted):
    maximum_value = max(to_be_sorted)
    max_exponent = len(str(maximum_value))
    being_sorted = to_be_sorted[:]

    for exponent in range(max_exponent):
        position = exponent + 1
        index = -position

        digits = [[] for i in range(10)]

        for number in being_sorted:
            number_as_a_string = str(number)
            try :
                digit = number_as_a_string[index]
            except IndexError:
                digit = 0
            digit = int(digit)

            digits[digit].append(number)

        being_sorted = []
        for numeral in digits:
            being_sorted.extend(numeral)

    return being_sorted

unsorted_list = [839, 12, 30, 40]
ordered_list = radix_sort(unsorted_list)
print(ordered_list)
