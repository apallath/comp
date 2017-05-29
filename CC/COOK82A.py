T = input()
for t in range(T):
    goals = dict()
    for i in range(4):
        [team,wins] = raw_input().strip().split()
        wins = int(wins)
        goals[team] = wins
    if goals["Barcelona"] > goals["Eibar"] and goals["Malaga"] > goals["RealMadrid"]:  
        print "Barcelona"
    else:
        print "RealMadrid"
        
