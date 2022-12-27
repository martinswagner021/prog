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

steps = []

def find_way():
    neighbourhood = [
        [position[0]+1, position[1]],
        [position[0], position[1]+1],
        [position[0]-1, position[1]],
        [position[0], position[1]-1],
    ]

    allowed_steps = []

    _ = []
    for i in neighbourhood:
        if i[0]<0 or i[1]<0:
            _.append(i)
    for i in _:
        neighbourhood.remove(i)

    for i in neighbourhood:
        if(maze[i[0]][i[1]] == '.'):
            allowed_steps.append(i)

    return random.choice(allowed_steps)

while(position != objective):
    next_step = find_way()
    steps.append(next_step)
    position = next_step
    maze[position[0]][position[1]] = '@'
    for i in maze:
        print(i)
    print(50*'#')