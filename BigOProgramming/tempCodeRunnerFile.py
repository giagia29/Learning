if backyard[u[0]][u[1]] == 'v':
            wolf += 1
        elif backyard[u[0]][u[1]] == 'k':
            sheep += 1    
        
        if u[0] == 0 or u[0] == n - 1 or u[1] == 0 or u[1] == m - 1:
            case_escape = True