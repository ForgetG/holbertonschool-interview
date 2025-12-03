#!/usr/bin/python3


'''
 canUnlockAll - Determine if all boxes can be unlocked.
'''

def canUnlockAll(boxes):
    '''Determine if all boxes can be unlocked.

    Args:
        boxes (list of list of int): A list where each sublist represents a box
                                      and contains the keys to other boxes. Box 0 is initially unlocked.
    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    '''
    unlocked = set()
    to_visit = [0]

    while to_visit:
        current_box = to_visit.pop()
        if current_box not in unlocked:
            unlocked.add(current_box)
            for key in boxes[current_box]:
                if key not in unlocked:
                    to_visit.append(key)

    return len(unlocked) == len(boxes)
