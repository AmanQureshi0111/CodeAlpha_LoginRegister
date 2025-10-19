# Login and Register
⚙️ How It Works

Registration (registerUser)

Takes username and password as input.

Checks if the username already exists in users.txt.

Validates password length.

Stores the new user in the file as:

username password


Login (loginUser)

Reads the file line by line.

Verifies if entered credentials match.

Displays success or error messages accordingly.

File Storage

Uses a single file users.txt for simplicity.

Example file content:

aman123 pass123
john456 qwerty

🧠 Sample Run
========== MENU ==========
1. Register
2. Login
3. Exit
Enter your choice: 1

--- Registration ---
Enter username: aman
Enter password: pass123
✅ Registration successful! You can now log in.

========== MENU ==========
1. Register
2. Login
3. Exit
Enter your choice: 2

--- Login ---
Enter username: aman
Enter password: pass123
✅ Login successful! Welcome, aman.
