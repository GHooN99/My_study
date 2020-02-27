#클래스 상속

class Person :
    def __init__(self):    # 기반클래스 속성 초기화
        print("Person init")
        self.hello = '안녕하세요'
    def greeting(self):
        print(self.hello)

class Student(Person): # 상속
    def __init__(self): # 상속 클래스 속성초기화
        super().__init__() # 기반클래스 __init__ 호출 
        print("Student init")
        self.school = ' asdf '
    def greeting(self):
            super().greeting() # 메서드 오버라이딩
            print("안녕!") 
    def study(self):
        print(self.school)
#상속 클래스에서 super init 을 써서 기반클래스 속성 초기화
#상속된 클래스에서 init 이 없으면 super없어도 됨 

kim = Student()
print(kim.school) #속성출력 ->student 초기화 후 출력
print(kim.hello) # super().__init()없으면 실행오류
kim.greeting() #Person 의메서드
kim.study()

##다이아몬드 상속(다중상속 이용)
class A:
    def f(self):
        print("A")
class B(A):
    def f(self):
        print("B")
class C(A):
    def f(self):
        print("C")      
class D(B,C): #다중 상속 
    pass

print(D.mro()) #메서드 탐색순서 확인
x=D() #B 부터 실행 왼쪽부터 상속  
x.f()


## 추상클래스
from abc import *

class StudentBase(metaclass=ABCMeta):  #인스턴스로 만들수 없다 상속에만 사용
    @abstractmethod  #추상 클래스 
    def study(self):
        pass
    @abstractmethod
    def go_to_school(self):
        pass
class Student1(StudentBase): # 추상클래스 상속 받을때   @abstractmethod 모두 구현 
    def study(self):
        print("study!!")
    def go_to_school(self):
        print("go!!")


lee = Student1() 
lee.study()
lee.go_to_school()
    
    


