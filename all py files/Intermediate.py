# from collections import namedtuple
# import json


# pt = namedtuple('Point','x,y,z')
# p = pt(11,43,52)
#
# print(p.x)
# print(p.y)
# print(p.z)
# print(p)


# from collections import deque
# li = deque()
# li.append('rozin')
# li.append('eshan')
# li.append('ahmed')
# li.append('rifat')
# li.append('sujon')
# li.append('rami')
# print(li)
# li.rotate()
# print(li)



# from collections import OrderedDict
#
# Dict = OrderedDict() #Ordered dict is no more necessary because all dict are ordered by default since python 3.7 version
# Dict['name']='rozin'
# Dict['city']='noakhali'
# Dict['country']='bangladesh'
# Dict['age']=19
# print(Dict)

# from collections import defaultdict
# d = defaultdict(int)
# d['name']='rozin'
# d[2]=33
# d[3]=54
# d[5]=21
# print(d)

# from collections import Counter
# a = "aaaabbbccd"
# p = Counter(a)
# print(p)
# print(p.most_common(1))
# print(p.most_common(1)[0])
# print(p.most_common(1)[0][0])

# from itertools import product
#
# a = [1,2]
# b = [3,4]
# pro = product(a,b, repeat = 3)
# print(list(pro))

# from itertools import permutations
# a = [1,2,0]
# pro = permutations(a,2)
# print(list(pro))

# from itertools import combinations
# a = [1,2,0,6,44,58,23,16,54]
# x = combinations(a, 4)
# print(list(x))


# from itertools import combinations_with_replacement
# a = [1,2,0,6,44,58,23,16,54]
# x = combinations_with_replacement(a, 3)
# print(list(x))

# from itertools import accumulate
# import operator
# a = [1,2,6,16,54]
# x = accumulate(a)
# print(list(x))
#
#
# from itertools import accumulate
# import operator
# a = [1,2,6,16,54]
# x = accumulate(a,func=operator.mul)
# print(list(x))
#
# from itertools import accumulate
# import operator
# a = [1,2,6,16,54]
# x = accumulate(a,func=max)
# print(list(x))

# from itertools import groupby
# a = [1,2,6,44,58,23,16,54]
# b = groupby(a,lambda x: x+3)
#
# for i,z in b:
#     print((i),list(z))

# from itertools import count , cycle, repeat


# for i in count(10):
#     print(i)
#     if i==15:
         #break


# a =[1,2,3,4]
# for i in cycle(a):
#     print(i)

# for i in repeat(2,5):
#     print(i)

##Extra about Exceptions
# class Valuehigh(Exception):
#     pass
# class Valuelow(Exception):
#     def __init__(self,message,value):
#         self.message = message
#         self.value = value
#
# def valuehigh(x):
#     if x>100:
#         raise Valuehigh("Value higher than 100")
#     elif x<100:
#         raise Valuelow("Value is lower than 100",x)
#
# try:
#     valuehigh(23)
# except Valuehigh as e:
#     print(e)
# except Valuelow as e:
#     print(e)

# import json
#
# person = { 'name': 'rozin','city': 'noakhali','country': 'bangladesh','age': 19,'education':{
#     'jsc': 2018,
#     'ssc': 2020,
#     'hsc': 2022
# }}
# x = json.dumps(person,indent=1,separators=('; ',' = '))
# print(x)

#
# with open('person.json','w') as file:
#     json.dump(person,file,indent=4)

# import json
# rozin= {
#     'name': 'rozin',
#     'gender': 'male',
#     'children': False,
#     'age': 20
# }
# with open('rozin.json','r') as file:
#     z = json.load(file)
#     print(z)

# x = json.dumps(rozin)
# print(x)
# print(type(x))
# y = json.loads(x)
# print(y)
# print(type(y))
# class user:
#     def __init__(self,name,age):
#         self.name = name
#         self.age = age
#
# x = user('rozin',20)
#
# def encoding(o):
#     if isinstance(o,user):
#         return {'name':o.name,'age':o.age}
#     else:
#         raise TypeError("This is a type_error")
#
# ss = json.dumps(x,default=encoding)
#
# print(ss)


##Method of Encoding  Python Objects to Javascript Strings


# import json
# from json import JSONEncoder

# x = {
#     "name": 'rozin',
#     "age": 19,
#     "city": 'dhaka',
#     "country": 'bangladesh',
#     "married": False,
#     "education": {
#         'jsc':2018,
#         'ssc':2020,
#         'hsc':2022
#     }
#
# }

# xjson = json.dumps(x,indent=4)
# print(xjson)
#
# y = json.loads(xjson) ##Method of Decoding Javascript Strings to Python Objects
# print(y)
# with open('x.json','w') as file:
#     json.dump(x,file,indent=4) ##Method of Encoding Python Objects to Javascript Strings Files
#
# with open('x.json','r') as file:
#     z = json.load(file)  ##Method of Decoding Javascript Strings Files to Python Objects
#     print(z)




##Method of Encoding Custom Python Objects #1(easy)

# import json
# from json import JSONEncoder
# class user:
#     def __init__(self,name,age,married):
#         self.name = name
#         self.age = age
#         self.married = married
#
# def encoding(o):
#     if isinstance(o,user):
#         return {"name" : o.name,  "age":o.age, "married": o.married}
#     else:
#         raise TypeError("there is a type error")
#
# x = user('rozin',20,True)
# xjson = json.dumps(x,default=encoding)
# print(xjson)

##Method of Encoding Custom Python Objects #2(hard)

# import json
# from json import JSONEncoder
#
# class user:
#     def __init__(self,name,age):
#         self.name = name
#         self.age = age
# class UserEncoder(JSONEncoder):
#
#
#     def default(self,o):
#         if isinstance(o, user):
#             return {"name": o.name, "age": o.age,"Married": o.married}
#         return JSONEncoder.default(self,o)
#
# x = user('rozin',20)
# xjson = json.dumps(x,cls=UserEncoder)
# print(xjson)


##Method of Encoding Custom Python Objects #3 ( also hard)

# import json
# from json import JSONEncoder
#
# class user:
#     def __init__(self,name,age):
#         self.name = name
#         self.age = age
#
# x = user('rozin',20)
#
# class UserEncoder(JSONEncoder):
#    def default(self,o):
#         if isinstance(o, user):
#             return {"name": o.name, "age": o.age,"Married": o.married}
#         return JSONEncoder.default(self,o)
#
#
# xjson = UserEncoder().encode(x)
# print(xjson)
# print(f"name = {x.name},age = {x.age},married = {x.married}")

##Method of Decoding JS to Custom Python Objects #1


# xx = json.loads(xjson)
# print(xx)
# print(type(xx))
# print(xx['married'])


#Random module

# import random
#
# x= random.random()
# print((x))

# import random
#
# x= random.uniform(1,9) #prints a random float
# print((x))

# import random
#
# x = random.randint(0,9) #prints a random integer including the last number which is 9 here
# print(x)

# import random
#
# x = random.randrange(0,9) #prints a randominteger except the last number
# print(x)

# import random
# x = random.normalvariate(0,5)
# print(x)

# import random
#
# x = ['w','e','t']
# c = random.choice(x) # prints a random object from the list
# print(c)

# import random
#
# x = ['w','e','t']
# c = random.sample(x,2) # prints a number of random object from the list
# print(c)

# import random
#
# x = ['w','e','t','r','y','d']
# c = random.choices(x,k = 3) # prints a random object  multiple times from the list
# print(c)

#these are all psuedo random functions as they can be reproduced

# import random
#
# random.seed(1)
# print(random.random())
#
# random.seed(2)
# print(random.random())
#
# random.seed(1)
# print(random.random())
#
# random.seed(2)
# print(random.random())





