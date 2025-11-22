import random
import string

char_vals = string.ascii_letters+string.digits+string.punctuation

length = int(input("Enter your password length: "))

p = "".join([random.choice(char_vals) for i in range(length)])

print("Generated Password =",p)    

