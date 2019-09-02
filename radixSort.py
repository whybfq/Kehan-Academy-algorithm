[Radix Sort](https://www.codecademy.com/paths/computer-science/tracks/sorting-algorithms/modules/cs-radix-sort/lessons/radix-sort-python/exercises/rendering-the-list)




'''
@created Sept 2th, 2562BE

Radix Sort:

Takes numbers in an input list.
Through each digit in those numbers, from least to most significant.
Looks at the values of those digits.
Buckets the input list according to those digits.
Renders the results from that bucketing.
Repeats this process until the list is sorted.
does! Feel free to play around with the solution code, see if there’s anything you can improve a
'''


def radix_sort(to_be_sorted):
    max_exponent = len(str(max(to_be_sorted)))
    being_sorted = to_be_sorted[:]

    for exponent in range(max_exponent):
        position = exponent + 1
        index = -position

        # creating the buckets which will be filled with the numbers in being_sorted
        digits = [[] for i in range(10)]

        for item in being_sorted:
            item_as_a_string = str(item)
            try :
                digit = int(item_as_a_string[index])
            except IndexError:
                digit = 0

            digits[digit].append(item)

        being_sorted = []
        for numeral in digits:
            being_sorted.extend(numeral)

    return being_sorted

unsorted_list = [830, 921, 163, 373, 961, 559, 89, 199, 535, 959, 40, 641, 355, 689, 621, 183, 182, 524, 1]

print(radix_sort(unsorted_list))



Output:
[1, 40, 89, 163, 182, 183, 199, 355, 373, 524, 535, 559, 621, 641, 689, 830, 921, 959, 961]
