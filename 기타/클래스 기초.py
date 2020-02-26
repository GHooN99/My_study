class Person: #클래스 선언 
    def __init__(self,name,age,address):   #인스턴스 속성 초기화 
        self.hello ='hello'
        self.name=name
        self.age = age
        self.__address=address #(__xxx 비공개 속성)
    def greeting(self):
        print(self.hello,self.name,'!')
    def printAddress(self):
        print(self.__address) #안에서만 접근가능 

james = Person('james' ,20,'Seoul')
kim = Person('Kim',21,'Busan')
james.greeting()
kim.greeting()
print(kim.age) #인스턴스 속성 바깥에서 접근
#print(kim.address) # 접근 불가 (비공개 속성) #중요한 값이고 함부로 바꾸면 안될때 
kim.printAddress() # 가능 


class Person2 :
    bag = [] #클래스 속성
    __hi = 'hi' #비공개 클래스 속성
    def put_bag(self,stuff):
        #self.bag.append(stuff) # self 는 인스턴스 뜻함 클래스 이름으로 접근 
        Person2.bag.append(stuff)
lee = Person2()
lee.put_bag('책')
B = Person2()
B.put_bag('연필')
print(lee.bag,B.bag) #공유 되버림 #공유 안되려면 인스턴스 속성으로 
print(Person2.bag)

#정적 메서드

class Calc:
    @staticmethod #정적 메서드 @ 는 데코레이터 , self 없음
    def add(a,b):
        print(a+b)
    @staticmethod
    def mul(a,b):
        print(a*b)

Calc.add(4,2)  # 바로 메서트 호출 
Calc.mul(4,5)

#클래스 메서드

class Myclass:
    count = 0 # 클래스 속성
    def __init__(self):   #인스턴스 만들어질때 1 더함
        Myclass.count+=1

    @classmethod
    def print_count(cls): #cls 붙여야함
        print(cls.count)
a=Myclass()
b=Myclass() # count =2
Myclass.print_count() #클래스 메서드

    
##코딩도장 문제
class Annie:
    def __init__(self,health, mana, ability_power):
        self.health = health
        self.mana = mana
        self.ability_power = ability_power
    def tibbers(self):
        print("티버: 피해량",self.ability_power*0.65+400)


health, mana, ability_power = map(float, input().split())
x = Annie(health=health, mana=mana, ability_power=ability_power)
x.tibbers()




    
