from queue import Queue

card_values = {
    "2": 1,
    "3": 2,
    "4": 3,
    "5": 4,
    "6": 5,
    "7": 6,
    "8": 7,
    "9": 8,
    "T": 9,
    "J": 10,
    "Q": 11,
    "K": 12,
    "A": 13,
}

n = int(input())

for i in range(n):
    player1 = Queue(input().split())
    player2 = Queue(input().split())
    p1_cards = {
        "2": 0,
        "3": 0,
        "4": 0,
        "5": 0,
        "6": 0,
        "7": 0,
        "8": 0,
        "9": 0,
        "T": 0,
        "J": 0,
        "Q": 0,
        "K": 0,
        "A": 0,
    }
    p2_cards = {
        "2": 0,
        "3": 0,
        "4": 0,
        "5": 0,
        "6": 0,
        "7": 0,
        "8": 0,
        "9": 0,
        "T": 0,
        "J": 0,
        "Q": 0,
        "K": 0,
        "A": 0,
    }

    for i in player1:
        p1_cards[i] += 1
    for i in player2:
        p2_cards[i] += 1

    draw = False
    while len(player1) > 0 and len(player2) > 0:
        a = player1[0]
        b = player2[0]
        if p1_cards[a] == len(player1) and p2_cards[a] == len(player2):
            draw = True
            break

        player1.popleft()
        p1_cards[a] -= 1
        player2.popleft()
        p2_cards[b] -= 1
        if card_values[a] > card_values[b]:
            player1.append(b)
            p1_cards[b] += 1
        elif card_values[a] < card_values[b]:
            player2.append(a)
            p2_cards[a] += 1
        else:
            player1.append(a)
            player2.append(b)
            p1_cards[a] += 1
            p2_cards[b] += 1

    if draw == True:
        print("draw")
    elif len(player1) > 0:
        print("player 1")
    else:
        print("player 2")
