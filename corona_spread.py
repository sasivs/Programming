from collections import deque

def is_valid_tile(row, col, M, N):
    return row >= 0 and row < M and col >= 0 and col < N

def min_stones_to_contain_corona(M, N, start_row, start_col):
    # Create a grid to represent the room
    room = [[0] * N for _ in range(M)]

    # Mark the starting tile as infected
    room[start_row][start_col] = -1

    # Define the adjacent directions (up, down, left, right)
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    # Perform breadth-first search to simulate the spread of corona
    queue = deque([(start_row, start_col)])
    stones_needed = 0
    turns = 0

    while queue:
        turns += 1
        if turns % 5 == 0:
            # Check for uninfected tiles adjacent to infected tiles
            for _ in range(len(queue)):
                row, col = queue.popleft()

                for dx, dy in directions:
                    new_row, new_col = row + dx, col + dy

                    if is_valid_tile(new_row, new_col, M, N) and room[new_row][new_col] == 0:
                        # Throw a stone to prevent infection
                        room[new_row][new_col] = -1
                        queue.append((new_row, new_col))

        else:
            # Continue spreading the infection
            for _ in range(len(queue)):
                row, col = queue.popleft()

                for dx, dy in directions:
                    new_row, new_col = row + dx, col + dy

                    if is_valid_tile(new_row, new_col, M, N) and room[new_row][new_col] == 0:
                        # Mark the tile as infected
                        room[new_row][new_col] = 1
                        stones+=1

    return stones_needed
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def min_stones(queue, turns, room):
    if len(queue) == 0:
        return 0
    if (turns%5) == 0:
        for _ in range(len(queue)):
            row, col = queue.popleft()

            for dx, dy in directions:
                new_row, new_col = row + dx, col + dy

                if is_valid_tile(new_row, new_col, M, N) and room[new_row][new_col] == 0:
                    room[new_row][new_col] = -1
                    queue.append((new_row, new_col))

# Read the number of test cases
t = int(input())

for _ in range(t):
    # Read the dimensions of the room and the starting point of corona
    M, N = map(int, input().split())
    X, Y = map(int, input().split())

    # Find the minimum number of stones required to stop corona spread
    stones_needed = min_stones_to_contain_corona(M, N, X, Y)

    # Print the result
    print(stones_needed)