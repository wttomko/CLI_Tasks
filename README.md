# Simple Task Manager

[Project Repository](https://github.com/wttomko/CLI_Tasks.git)

This project is a **Command-Line Interface (CLI) Task Manager** written in C++ using the [nlohmann/json](https://github.com/nlohmann/json) library for handling JSON data. The program allows users to manage tasks stored in a `Tasks.json` file.

## How it Works

### 1. **Initialization**
- The program checks if the `Tasks.json` file exists.
- If the file does not exist, it creates a new file and initializes it with an empty JSON array.

### 2. **Menu Display**
- The program clears the console and displays a menu with the following options:
  - **[1] Add Task**: Add a new task with a description.
  - **[2] Remove Task**: Remove a task by its ID.
  - **[3] Mark Task as Completed**: Mark a specific task as completed.
  - **[4] Mark Task as Incomplete**: Mark a specific task as incomplete.
  - **[5] Clear All Tasks**: Delete all tasks from the list.
  - **[6] Exit**: Exit the program.

  **Options 2, 3, and 4 all require exactly 2 inputs from the user: The number 2,3, or 4 -followed by the number of the task you wish to change/remove**

### 3. **User Input**
- The program waits for the user to input a choice.
- Based on the input, it performs the corresponding action.

### 4. **Task Manaaddgement**
- **Add Task**: Prompts the user for a task description, creates a new `Task` object, and appends it to the `Tasks.json` file.
- **Remove Task**: Deletes a task by its ID and reassigns IDs to remaining tasks.
- **Mark Task as Completed/Incomplete**: Updates the `isCompleted` status of a task in the `Tasks.json` file.
- **Clear All Tasks**: Resets the `Tasks.json` file to an empty array.

### 5. **Task Display**
- The program uses the `printTasks()` function to display all tasks in the `Tasks.json` file. This is automaticlly displayed as part of the main menu.
  - Completed tasks are shown in **blue**.
  - Incomplete tasks are shown in **red**.

### 6. **Exit**
- The program exits when the user selects the "Exit" option or enters `Q`.

## Example Workflow
1. Run the program.
2. Add a task by selecting option `[1]` and entering a description.
3. View the task list with completed and incomplete tasks.
4. Mark a task as completed or incomplete using options `[3]` or `[4]`.
5. Remove a task using option `[2]`.
6. Clear all tasks using option `[5]`.
7. Exit the program using option `[6]` or `Q`.

## Dependencies
- **nlohmann/json**: Used for reading and writing JSON data.
- **C++ Standard Library**: Includes `<iostream>`, `<fstream>`, and `<string>`.

## Notes
- Ensure the `Tasks.json` file is in the same directory as the executable.
- If the file is missing or corrupted, the program will reinitialize it with an empty array.

This program provides a simple and efficient way to manage tasks directly from the command line.