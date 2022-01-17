if __name__ == '__main__':
    alphabet = [0 for _ in range(26)]
    n = int(input())
    sentence = input()
    sentence = sentence.lower()
    for character in sentence:
        result = ord(character) - 97
        alphabet[result] += 1
    
    check = True
    for i in range(len(alphabet)):
        if alphabet[i] == 0:
            check = False
            print('NO')
            break
    
    if check == True:
        print('YES')