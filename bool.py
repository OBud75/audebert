
def bool (a,b,c,d):
    f = not(a and (not b) and (a or b)) or (not a and b and not(a or (not b ) or (not c )))
    g = not((c or d) and a and not(c) and d and ((not a) and c or (not d)))
    s1 = a and (a or b ) #true 
    s2 = (a or b) and ((not a) or b) #true 
    s3 = (a and (not b) or c ) and ( a  or (not b )) # 0 0=0  1 0=0 0
    s4 = (a and b ) or c and (not a) or (b and c) and (not b) #1 
    s5 = (a or b or c) and (not a or b or c) or (a and b) or c and d
    s6 = a or b or (not c) and b or (a or not c) or not ((not a ) or b or ((not a )and c))
    return f,g,s1,s2,s3,s4,s5,s6  

class Person():
    def is_major(self):
        return self.age >= 18

toto = Person()
toto.age = 20

titi = Person()
titi.age = 15

nana = Person()
nana.age = 56

nono = Person()
nono.age = 42


a = toto.is_major()
b = not(titi.is_major())
c = nana.is_major()
d = nono.is_major()

print(bool(a,b,c,d))
print(bool(1,0,1,0))