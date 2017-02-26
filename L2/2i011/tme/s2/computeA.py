def suite(n):
    a0=11/2
    a1=61/11
    for i in range(n-2):
        tmp=(111-((1130-(3000/a0))/a1))
        a0=a1
        a1=tmp
    return a1
