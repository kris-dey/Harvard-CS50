from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    same = []
    a1 = a.splitlines()
    b1 = b.splitlines()

    for line in a1:
        s = False
        for line2 in b1:
            for line3 in same:
                if line == line3:
                    s = True
            if line == line2 and s == False:
                same.append(line)
    return same


def sentences(a, b):
    """Return sentences in both a and b"""

    same = []
    a1 = sent_tokenize(a)
    b1 = sent_tokenize(b)

    for sent in a1:
        s = False
        for sent2 in b1:
            for sent3 in same:
                if sent == sent3:
                    s = True
            if sent == sent2 and s == False:
                same.append(sent)
    return same


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    same = []
    a1 = func(a, n)
    b1 = func(b, n)

    for line in a1:
        s = False
        for line2 in b1:
            for line3 in same:
                if line == line3:
                    s = True
            if line == line2 and s == False:
                same.append(line)
    return same

#to convert into subtrings
def func(c, n):

    d = []
    l = len(c)
    i = 0
    for j in range(n, l + 1, 1):
        d.append(c[i:j])
        i = i + 1

    return d