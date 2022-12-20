# It is a probability AI that defends a random penalty kick, actually it seems like a probability tester

import random

goal_score = 0
test_cases = 10000

# Side picked up randomly
for i in range(test_cases):
    shooter_side = random.randint(0,1)
    gk_side = random.randint(0,1)

    if(shooter_side != gk_side):
        goal_score = goal_score + 1

print(f'Picked up randomly: {goal_score}')
goal_score = 0

# Based on the percentage that came out to the current moment
last_sides = []
for i in range(test_cases):
    shooter_side = random.randint(0,1)
    if(i==0):
        gk_side = random.randint(0,1)
    else:
        last_shoot_percentage = sum(last_sides)/len(last_sides)
        if(last_shoot_percentage > 0.5):
            gk_side = 1
        else:
            gk_side = 0

    if(shooter_side != gk_side):
        goal_score = goal_score + 1

    last_sides.append(shooter_side)

print(f'Based on the percentage: {goal_score}')