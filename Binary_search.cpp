def binarySearch():
    left = 0
    right = n
    while left < right:
        mid = (left+right)//2
        if a[mid] == key:
            return mid
        elif key < a[mid]:
            right = mid
        else:
            left = mid + 1
    else:
        return not_found