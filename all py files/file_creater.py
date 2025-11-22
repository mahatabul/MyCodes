import os
from datetime import datetime

def create_files():
    print("Enter how many and what type of file(s) you want to create.")
    file_type = input("File name and type (e.g., t.txt, d.docx): ").strip()
    r = int(input("How many files do you want to create?: "))
    
    # Handling invalid input
    if '.' not in file_type:
        print("Invalid file format. Please enter a valid file name and extension (e.g., t.txt).")
        return
    
    file_name, extension = file_type.split(".")
    
    # Ask for directory to create files in
    directory = input("Enter the directory path to save files (leave empty to use current directory): ").strip()
    if directory and not os.path.exists(directory):
        os.makedirs(directory)
        print(f"Directory '{directory}' created.")
    
    # Generate and create files
    for i in range(1, r + 1):
        try:
            # Create unique file name for each file
            file_path = os.path.join(directory, f"{file_name}_{i}.{extension}")
            
            with open(file_path, "w") as f:
                # Writing unique content with a timestamp
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                f.write(f"This is file {i} of type {extension}.\n")
                f.write(f"Created on: {timestamp}\n")
            
            print(f"File {i} created at: {file_path}")
        
        except Exception as e:
            print(f"An error occurred while creating file {i}: {e}")
    
    print("Task completed successfully.")

# Run the function
create_files()
