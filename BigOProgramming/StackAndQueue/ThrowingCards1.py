import queue
discarded_cards = []
def draw_card(n : int, deck : queue):
  count = 1
  while deck.qsize() != 1:
    if count % 2 == 1:
      discarded_cards.append(deck.get())
      count += 1
    else:
      value = deck.get()
      deck.put(value)
      count += 1

while True:
  n = int(input())
  if n == 0:
    exit(0)
  deck = queue.Queue()
  for i in range(1, n + 1):
    deck.put(i)
  draw_card(n, deck)
  print('Discarded cards:', end=(' ' if n > 1 else ''))
  print(*discarded_cards, sep=', ')
  print('Remaining card: ', deck.get())