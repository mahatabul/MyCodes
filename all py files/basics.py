#VARIABLES

# name = "rozin"
# f = "hi"
# print(f)
# print(name)


#EXPRESSION & STATEMENTS

 #an expression is something in code that returns value
#all we write in a program is statement. a program is formed of statements
#because its doing something to the value

#name="rozin";print(name)

#here name is a variable which holds rozin . rozin is a string which is a expression here.
# the whole line is a statement.


#COMMENTS

#comments are just notes written by programmers just to recall or understand their codes afterwards. they do nothing is a program.
#anything after a '#' is a comment.


# DATATYPES

#python has many builtin datatype such as string,integers,list,tuple,dictionary etc

#name = "rozin"
# print(type(name))
#print(isinstance(name,str))
# age =20.88
# print(type(age))


#ARITHMATIC_OPERATORS

# +,-,*,/,//,%,**
#addition,substraction,multiplication,division,floor division,remainder,exponention(power)


#COMPARISON_OPERATORS

#a==b a!=b a>b a<b a>=b a<=b


#LOGICALOPERATORS

# or
# and
# not

# print(0 or 1)
# print(1 or 0)
# print(True or False)
# print(False or True)
# print("hey" or True)
# print(True or "hey")
# print([] or False)
# print(False or [])
#or always tries to print the first operand but if it's False then it prints the second one no matter what it is
# it is attracted to Truth .

# print(0 and 1)
# print(1 and 0)
# print(1 and 'hey')
# print('hey' and 1)
# print('hi' and 'hey')
#print([] and False)#it considers absence of true as false
#print(False and [])
#and tries to print the first operand but if it's True then it prints the second one no matter what it is
# it is attracted to False .


#BITWISE-OPERATORS

# & performs binary AND
# | performs binary OR
# ^ performs binary XOR
# ~ performs binary NOT
# << shift left operation
# >> shift right operation


#MORE

#(is) is called identity operator used to compare if both objects are same
# (in) is called membership operator used to tell if a value is in a list


#TERNARY_OPERATOR

# def age(a):
#     return True if a > 18  else False
# print(age(55))
#basically it is an if else statement in one line (in short)


#STRINGS

#series of characters in "" or ''. both sides quotations should be same.
# case1
# name = "rozin"
# phrase = " is my name"
# name+=phrase
# print(name)
#case2
# name = "rozin"
# name+= " is my name"
# print(name)

#TYPECASTING

#typecasting only works in simply turning int to str or int to float or int to double but u can't turn a str into a int
#so it doesn't always work
#age=str(20)
#print(type(age))#returns str


# STRING

# print("rozin".isupper()) returns false #print("ROZIN".isupper()) returns true
# print("ROZIN".islower()) returns false #print("rozin".islower()) returns true
# print("rozin".upper()) returns ROZIN
# print("ROZIN".lower()) returns rozin
#print("rozin".title())
# print("""rozin
# is my
# name""") (print multi lines with three times quotation.)
#name = "rozin"
#print(len(name)) #returns length of str 5

# name="Rozin"
# print("zo"in name)


#ESCAPING_CHARACTERS

# name = "RO\"zin" (put a backslash before a double quote and problem solved and single quote ' doesn't make any problem)
# print(name) (returns Ro"zin)
#print("rozin\nis my name")#create new line with \n same as c program laguage

# name="rozin"
# print(name[1:4])

#BOOL

# done = False
# if done:
#     print("yes")
# else:
#     print("no")
# ingr = True
# mealcooked = False
# mealready=all([ingr,mealcooked])
# print(mealready)


#COMPLEX_NUMBERS
# num1=2+3j
# num2=complex(5,6)
# print(num1.real,num1.imag)
# print(num2.real,num2.imag)


#BUILTIN_FUNCTIONS

# print(round(5.389,2))(returns 5.9)
# print(abs(-59))(returns 59)


#ENUM

# from enum import Enum
#
# class video(Enum):
#     active=1
#     inactive=0
# print(video(1))


#USER_INPUT
#x=input("enter your name:")
#print(x)

#CONTROL_STATEMENT
# print("Enter your name")
# x= input(":")
# if x=="Rozin":
#     condition = True
# else:
#     condition = False
#
# while condition == True:
#     print("Hello Rozin\nHow are you?")
#     break
#
# while condition == False:
#     print("who are you?")
#     break

#LIST & ITS METHODS
# li =  ['q','w','e','r','t']
# li.extend([1,2,3])
# print(li)

# lis = li + [1,2,3,4]
#print(lis)
# li2 =['y','u','i','o']
# li.insert(1,500)
# li.sort()
# print(li)
# print(li[:])
# x = sorted(li)
# print(li.index("w"))


#TUPLES
# tup = (1,2,3,10,4)
# x = tup + ('e','r','t')
# print(x)
#can't modify original tuple but can add things same as list


#DICTIONARIES
#dic = {"name": "rozin","age":19,"gender":"male","color":"red"}
# x=dic.items()# returns all items(keys+values)
# x = dic.get("name")# returns a specific value
#x = dic.keys()# returns keys such as name,age,gender.
#x = dic.values()# returns values such as rozin,19,male.
# d = dic.copy()# copies a dictionary
# print(d)
#print(list(x))
#print(dic.get("color","brown"))#returns the given value brown but if there is already a value such as red then it returns red.
# print(dic.pop("name"))#returns what it deleted pop method deletes a item(key+value)
# print(dic)#returns the dictionary where name is deleted
#del dic["name"] # also deletes a item like pop
#print(dic)
#print(dic.popitem()) #deletes the last item of dictionary
#print("age" in dic) #works only with keys not values


#SET
# set1= {"roger","doger","flor"}
# set2= {"oger","dger","flr"}
# print(set2)


#FUNCTIONS

# def hello(name="my friend"):
#     print(f"Hello {name}")
#hello("Rozin") #returns Hello Rozin
#hello()#returns Hello my friend

#NESTED-FUNCTIONS
# def talk(p):
#     def say(word):
#         print(word)
#
#     y = p.split(" ")
#     for x in y:
#         say(x)
# talk("i amma gonna ")
# def num():
#     number = 0
#     def say():
#         nonlocal number
#         number +=1
#         return number
#     return say
#
# say = num()
#
# print(say())
# print(say())
# print(say())

# def counter():
#     count = 0
#     def y():
#         nonlocal count
#         count +=1
#         return count
#     return y
#
#
# y = counter()
# print(y())
# print(y())
# print(y())

#OBJECT
#everything we see in python is object

#CLASS
# class animal:
#     def bark(self):
#         print("bark")
#
# class dog(animal):
#     def __init__(self,name,age):
#         self.name = name
#         self.age = age
#
#
#     def walking(self):
#         print("walking")
#
# x= dog("tamy",7)

# print(x.name)
# print(x.age)
# (x.walking())
# (x.bark())
#print(help(dog))




#MODULES

#math for math utilities
#re for regular expression
#json to work with JSON
#datetime to work with dates
#sqlite3 to use SQLite
#os for operating system
#random for random number generation
#statistics for statistics utilities
#requests for http network requests
# http to create http servers
# urlib to manage urls

#ACCEPTING ARGUEMENTS AND COMMANDLINE
# import sys
# name = sys.argv[1]
# print("hello" + name)
# import argparse
# parser = argparse.ArgumentParser(
#     description = 'this program print the name of my friends'
# )
#
# parser.add_argument('-c','--color',metavar='color',
#                     required=True, help='the color to search for')
# args = parser.parse_args()
# print(args.color)

#LAMBDA
#lambda are anoymous functions it is a short form of def
# x = lambda b,c:b+c
#
# print(x(2,3))

#MAP FILTER REDUCE

#li = [1,2,3,4]
# def multiply(a):
#     b = a*2
#     return b
# x = map(multiply,li)
# print(list(x))
#y= lambda a: a+2
#x = map(y,li)
#print(list(map(lambda a : a*2,li)))

# li = [1,2,3,4]
# def even(a):
#
#     return a%2==0
# y = filter(even,li)
# print(list(y))
#
# from functools import reduce
# li = [
#     ('dinner',30),
#     ('room',100),('tour',100),('books',100),('tution',100)
#
# ]
# x = lambda a,b : a+b
# sum = reduce(x,[i[1] for i in li])
# print(sum)

# recursion

# def fact(n):
#     if n==1 or n==0:
#         return 1
#     else:
#         return n*fact(n-1)
#
# print(fact(0))
# print(fact(1))
# print(fact(2))
# print(fact(3))
# print(fact(4))
# print(fact(5))

#DECORATORS

# def logtime(func):
#     def wrapper():
#         print("before")
#
#         print("after")
#         val = func()
#
#         return val
#     return wrapper
# @logtime
# def hello():
#     print("hello")
#
# hello()


#ANNOTATIONS
# def increment(n: int )-> int:
#     return n+1
# x : int = 0


#EXCEPTIONS

# try:
#     print(hello)
# except:
#     print("bhul hoise")

# try:
#     print(x)
# except NameError: # u can use this syntax if u want to print different different line for different different errors
#     print("NameError") #works for all types of errors as far as i know
# except SyntaxError:
#       print("SyntaxError")
# else:
#     print("hello")
# finally:
#     print("hi")



#jodi bhodrobhave error dekhte chan tahole ei try except formula try korun but *** special note: ei formula SyntaxError e kaj kore na
# try:
#     print('jio')
# except Exception as errr:
#     print(errr)
#
# try:
#     print(hello)
# except Exception as errr:
#     print(errr)

# try:
#     print(2/0)
# except Exception as errr:
#     print(errr)

# try:
#     raise Exception('rozin')
# except Exception as r:
#     print(r)
# li = [1,2,3,4]
# x = sizeof(li)
# print(x)
# class dognotfound(Exception):
#     print('hi')
#     pass
# try:
#     raise dognotfound()
# except dognotfound:
#     print('REr')
# filename = 'F:\Freecodecamp\N.txt'
# with open(filename,'N.txt') as  file:
#     content = file.read()
#     print(content)

# polymorphisim
# class cat:
#     def eat(self):
#         print("cat eating cat food")
#
# class dog(cat):
#     def eat(self):
#         print("dog eating dog food")
#
#
# dog = dog()
# cat = cat()
# cat.eat()
# dog.eat()

#Operator Overloading

# Operator Overloading is a technique to make classes comparable and use operators or load operators in them

# class ss:
#     def __init__(self,name,age,gender):
#         self.name = name
#         self.age = age
#         self.gender = gender
#     def __gt__(self, other):
#         return True if self.age > other.age else False
#
# eshan = ss('eshan',135,'male')
# rozin = ss('rozin',19,'male')
#
# print(eshan.age > rozin.age)

# __add__() respond to the + operator
# __sub__() respond to the - operator
# __mul__() respond to the * operator
# __truediv__() respond to the / operator
# __floordiv__() respond to the // operator
# __mod__() respond to the % operator
# __pow__() respond to the ** operator
# __rshift__() respond to the >> operator
# __lshift__() respond to the << operator
# __and__() respond to the & operator
# __or__() respond to the | operator
# __and__() respond to the & operator
# __xor__() respond to the ^ operator


print("heiiii")
