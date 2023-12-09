import random

maze = [
    ['#','#','#','#','#','#','#','#','#','#'],
    ['.','.','.','.','#','#','#','#','#','#'],
    ['#','.','#','#','#','#','#','#','#','#'],
    ['#','.','#','#','#','#','#','#','#','#'],
    ['#','.','#','#','#','#','#','#','#','#'],
    ['#','.','.','.','.','.','.','.','#','#'],
    ['#','#','#','#','#','#','#','.','#','#'],
    ['#','#','#','#','#','#','#','.','.','.'],
    ['#','#','#','#','#','#','#','.','#','#'],
    ['#','#','#','#','#','#','#','.','#','#'],
    ['#','#','#','#','#','#','#','#','#','#'],
]

# All coordinates are based on the maze matrix
origin = [1,0]
maze[origin[0]][origin[1]] = '@'

objective = [7,9]

# Be careful with pointers lol
position = [origin[0],origin[1]]

history_steps = []

def find_way():
    neighbourhood = [
        [position[0]+1, position[1]],
        [position[0], position[1]+1],
        [position[0]-1, position[1]],
        [position[0], position[1]-1],
    ]

    allowed_steps = []

    for i in neighbourhood:
        if i[0]>=0 and i[1]>=0 and maze[i[0]][i[1]] == '.':
            allowed_steps.append(i)

    # if it is empty, marks as not the path and then goes back
    if not allowed_steps:
        temp = history_steps.pop()
        maze[temp[0]][temp[1]] = 'x'
        return history_steps.pop()

    return random.choice(allowed_steps)

while(position != objective):
    next_step = find_way()
    history_steps.append(next_step)
    position = next_step
    maze[position[0]][position[1]] = '@'
for i in maze:
    print(i)