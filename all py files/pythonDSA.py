# 1st index and end index using Binary search in Python (decending order)

# def first_loc(li, qury, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]

#         if (mid_num == qury):
#             if (mid-1>=0 and li[mid - 1] == qury):
#                 h = mid - 1
#                 first_loc(li, qury, l, h) # recursion
#             else:
#                 return mid;break

#         elif (mid_num > qury):
#             l = mid + 1
#         elif (mid_num < qury):
#             h = mid - 1

#     return -1


# def last_loc(li, qury, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]

#         if (mid_num == qury):
#             if (mid+1<len(li) and li[mid + 1] == qury):
#                 l = mid + 1
#                 last_loc(li, qury, l, h) # recursion
#             else:
#                 return mid; break


#         elif (mid_num > qury):
#             l = mid + 1
#         elif (mid_num < qury):
#             h = mid - 1

#     return -1


# 1st index and end index using Binary search in Python (ascending order)

# def first_loc(li, qury, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]
#
#         if (mid_num == qury):
#             if (mid - 1 >= 0 and li[mid - 1] == qury):
#                 h = mid - 1
#                 first_loc(li, qury, l, h)  # recursion
#             else:
#                 return mid
#                 break
#
#         elif (mid_num > qury):
#             h = mid - 1
#         elif (mid_num < qury):
#             l = mid + 1
#
#     return -1
#
#
# def last_loc(li, qury, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]
#
#         if (mid_num == qury):
#             if (mid + 1 < len(li) and li[mid + 1] == qury):
#                 l = mid + 1
#                 last_loc(li, qury, l, h)  # recursion
#             else:
#                 return mid
#                 break
#
#
#         elif (mid_num > qury):
#             h = mid - 1
#         elif (mid_num < qury):
#             l = mid + 1
#
#     return -1
#
#
# def ans(li, qury, l, h):
#     f = first_loc(li, qury, l, h)
#     g = last_loc(li, qury, l, h)
#     return f, g
#
#
# # main code
# li = eval(input("Enter a list: "))
# li = list(li)
#
# qury = int(input())
#
# l = 0
# h = len(li) - 1
#
# f, g = ans(li, qury, l, h)
#
# print("first index = ", f) if f != -1 else print(-1)
# print("last index = ", g) if g != -1 else print(-1)


# Binarysearch_for_smallest element

# def binarysearch_for_smallest(li, q, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]
#
#         if (mid_num == q):
#
#             return mid
#             break
#
#         else:
#             if (mid_num > li[len(li) - 1]):
#                 l = mid + 1
#             else:
#                 h = mid - 1
#     return -1
#
#
# # main code
# li = eval(input())
# li = list(li)
# q = min(li)
#
# l = 0
# h = len(li) - 1
# f = binarysearch_for_smallest(li, q, l, h)
# print(f)

# def binarysearch_rotatedlist(li, q, l, h):
#     while l <= h:
#         mid = (l + h) // 2
#         mid_num = li[mid]
#         if (mid_num == q):
#             return mid
#             break
#         else:
#             if (mid_num > q and q > li[len(li) - 1]):
#                 h = mid - 1
#
#             elif (mid_num > q and q <= li[len(li) - 1]):
#                 l = mid + 1
#
#             elif (mid_num < q and q > li[len(li) - 1]):
#                 l = mid + 1
#             elif (mid_num < q and mid_num > li[len(li) - 1]):
#                 pass


# Binary search in rotated list [5,6,7,1,2,3]

# def binarysearch_rotatedlist(li, q):
#     l = 0
#     h = len(li) - 1
#
#     while l <= h:
#         mid = (l + h) // 2
#
#         if li[mid] == q:
#             return mid
#
#         if li[l] <= li[mid]:
#             if li[l] <= q < li[mid]:
#                 h = mid - 1
#             else:
#                 l = mid + 1
#         else:
#             if li[mid] < q <= li[h]:
#                 l = mid + 1
#             else:
#                 h = mid - 1
#
#     return -1  # element not found
#
#
# # main code
# li = eval(input())
# li = list(li)
# q = int(input())
# l = 0
# h = len(li) - 1
# f = binarysearch_rotatedlist(li, q)
# print(f)


# class User:
#     def __init__(self, name, username, email):
#         self.name = name
#         self.username = username
#         self.email = email
#         print("user printed")

#     def introduce(self, gname):
#         return f"Hello {gname} ! I'm {self.name} , my username is {self.username}. Contact me on {self.email}"

#     def __repr__(self):
#         return f"User(name={self.name}, username={self.username}, email={self.email})"

#     def __str__(self):
#         return self.__repr__()


# class userdatabase:
#     def __init__(self):
#         self.users = []

#     def insert(self, user):
#         i = 0
#         while i < len(self.users):
#             if self.users[i].username > user.username:
#                 break
#             i += 1
#         self.users.insert(i, user)

#     def find(self, username):
#         for user in self.users:
#             if user.username == username:
#                 return user

#     def update(self, user):
#         target = self.find(user.username)
#         if target:
#             target.name = user.name
#             target.email = user.email
#         else:
#             print("User not found")

#     def list_all(self):
#         return self.users


# lemon = User("Lemon", "lemon", "lemon123@hotmail.com")
# john = User("John", "john", "john203@fmail.com")
# anny = User("Canny", "anny", "anny2050@protonmail.com")
# jenny = User("Jenny", "jenny", "jenny11@email.com")
# database = userdatabase()
# new_anny = User("Anny","anny","anny2030@protonmail.com")
# database.insert(lemon)
# database.insert(john)
# database.insert(anny)

# print(database.list_all())

# database.update(new_anny)

# print(database.list_all())


# Binary Search tree


# class Treenode:
#     def __init__(self, key):

#         self.key = key
#         self.left = None
#         self.right = None

#     def size(self):
#         if self is None:
#             return 0
#         return 1 + Treenode.size(self.left) + Treenode.size(self.right)

#     def height(self):
#         if self is None:
#             return 0
#         return 1 + max(Treenode.height(self.left), Treenode.height(self.right))

#     def displaykey(self, space="\t", level=0):
#         if self is None:
#             print(space * level + "n")
#             return
#         if self.left is None and self.right is None:
#             print(space * level + str(self.key))
#             return
#         Treenode.displaykey(self.right, space, level + 1)
#         print(space * level + str(self.key))
#         Treenode.displaykey(self.left, space, level + 1)

#     @staticmethod
#     def parse_tuple(data):
#         if isinstance(data, tuple) and len(data) == 3:
#             node = Treenode(data[1])
#             node.left = Treenode.parse_tuple(data[0])
#             node.right = Treenode.parse_tuple(data[2])
#         elif data is None:
#             node = None
#         else:
#             node = Treenode(data)

#         return node

#     def to_tuple(self):
#         if self is None:
#             return None
#         if self.right is None and self.left is None:
#             return self.key
#         return Treenode.to_tuple(self.left), self.key, Treenode.to_tuple(self.right)

#     def traverseintree(self):
#         if self is None:
#             return None
#         return (
#             Treenode.traverseintree(self.left)
#             + [self.key]
#             + Treenode.traverseintree(self.right)
#         )

#     def __str__(self):
#         return "BinaryTree<{}>".format(self.to_tuple())

#     def __repr__(self):
#         return "BinaryTree<{}>".format(self.to_tuple())


# def remove_none(nums):
#     return [x for x in nums if x is not None]


# def is_bst(node):
#     if node is None:
#         return True, None, None

#     is_bst_l, min_l, max_l = is_bst(node.left)
#     is_bst_r, min_r, max_r = is_bst(node.right)

#     is_bst_node = (
#         is_bst_l
#         and is_bst_r
#         and (max_l is None or node.key > max_l)
#         and (min_r is None or node.key < min_r)
#     )
#     min_key = min(remove_none(min_l, node.key, min_r))
#     max_key = max(remove_none(max_l, node.key, max_r))

#     return is_bst_node, min_key, max_key


# class bstnode:
#     def __init__(self, key, value=None):
#         self.key = key
#         self.value = value
#         self.right = None
#         self.left = None
#         self.parent = None



# Hash table and python dict

print("pyhton dsa")