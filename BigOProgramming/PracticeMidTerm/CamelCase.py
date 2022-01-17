from queue import Queue

sentence = input()
q = Queue()
for chr in sentence:
    q.put(chr)
count = 1
while not q.empty():
    character = q.get()
    if character.isupper():
        count += 1
    
print(count)