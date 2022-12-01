'''Test-Driven-Development example'''

def all_bigger_five(numbers: list[int]) -> bool:
    '''returns true if all numbers in list are bigger than five'''

    if not isinstance(numbers, list): return False
    
    if len(numbers) == 0: return False

    if all([isinstance(x, (int, float)) for x in numbers]) == False: return False

    return all([n > 5 for n in numbers])


def test_all_bigger_five():
    assert all_bigger_five([6, 9, 13, 25]) == True

    assert all_bigger_five([5.1,7.8,13.50]) == True

    assert all_bigger_five([1, 2]) == False

    assert all_bigger_five([]) == False

    assert all_bigger_five([5,"as",2]) == False

    assert all_bigger_five(True) == False

    assert all_bigger_five([-6, -7]) == False

    assert all_bigger_five([-1, -2]) == False


if __name__ == "__main__":
    test_all_bigger_five()
    print("test passed")
