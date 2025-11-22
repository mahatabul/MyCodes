#Relax it's a simple to do list code. see u not for mind.

todolist = dict()
def entertodolist():
    x = input('Enter task number:')
    if x not in todolist:
        x2 = input("Enter your task:")
        todolist[x] = x2
        print("Updated Successfully.")
    else:
        print("Already have that task")




def show_specifictodolist():
    c = input("Search the task you want to see? : ")
    
    if c in todolist.keys():
        print(c,todolist[c])
    elif c in todolist.values():
        print(c)

    else:
        print("task not found".title())


def show_wholetodolist():
    print('serial \t task'.title())
    for c in todolist:
        print("{} \t     {}".format(c, todolist.get(c)))

def deletetodolist():
    show_wholetodolist()

    xx = input("Delete Task: ")
    if xx in todolist:
        todolist.pop(xx)
        print("Deleted successfully")
    else:
        print("Task not found")

def edit_todolist():
    show_wholetodolist()
    xx = input("Edit Task number: ")
    if xx in todolist:

        c = input("enter new task: ")
        todolist[xx] = c
        print("Updated Successfully.")

    else:
        print("Task not found")



print("""Hello!
Press( 1 )to start 'To Do List'""")
x1 = input(":")
while True:
    if x1 == "1":
        print("""What service do you want?
        [1] Enter To Do List Task
        [2] Search To Do List Task
        [3] Show whole To Do List Task
        [4] Delete To Do List Task
        [5] Edit To Do List Task
        [6] Exit
         """.title())
        x3 = input(":")
        if x3 == '1':
            entertodolist()


        elif x3 == '2':
            show_specifictodolist()

        elif x3 == '3':
            show_wholetodolist()

        elif x3 == '4':
            deletetodolist()

        elif x3 == '5':
            edit_todolist()



        else:
            break








