# 🏧 ATM Simulator in C

## Problem Statement

This project is a simple **ATM simulator written in C**.
It allows multiple users to log in with a username and pincode, and perform standard ATM operations:

- Deposit money
- Withdraw money
- Check account balance
- View transaction history (last 5 actions are saved)
- Logout (clears transactions and resets session)

This program demonstrates **structs, arrays, strings, input validation, and functions** in C.

---

## Features

- **Login system** with predefined users and pincodes
- **Deposit & Withdraw** with balance updates and validation
- **Balance inquiry** with formatted output
- **Transaction history** (capped at 5 recent actions)
- **Logout** resets session data
- **Error handling** for invalid inputs and insufficient funds

---

## 🚀 Usage

1. Compile the program

Make sure you have GCC installed, then compile with:

```sh
gcc atm.c -o atm

2. Run The program
./atm

3. Login credentials
Username. Pincode
karake.    0001
simeon.    0002
manzi.     0003
levis.     0004

4.Sample Run

-------- LOG IN ---------
Enter username (q to quit): karake
Enter pincode: 0001

Hello, karake!

============ ATM (SIMULATOR) ===========

Choose:
  (1) Deposit Money
  (2) Check Account Balance
  (3) Withdraw Money
  (4) Transaction history
  (5) Logout

(prompt) Choose action [1-4]: 1

$$ Enter amount to deposit: 100
++ $100.00 deposited successfully!

(prompt) Choose action [1-4]: 2

$$ Current Balance: $100.00

(prompt) Choose action [1-4]: 3

$$ Enter amount to withdraw: 40
-- Withdrawal of $40.00 successful.

$$ Current Balance: $60.00

(prompt) Choose action [1-4]: 4

------- Transaction History ---------
1. Deposited $100.00
2. Checked balance $0.00
3. Withdrew $40.00

(prompt) Choose action [1-4]: 5

... Goodbye! Thanks for using ATM Simulator ...


🏗️ Design Notes

Program Flow
1. User enters username (or quits with q).
2. Pincode is validated.
3. If valid → access to ATM menu.
4. ATM menu allows deposit, withdraw, check balance, or view history.
5. Logout clears transactions and returns to login screen.

Key Functions
• check_balance(balance) → Display balance
• deposit(current_balance, amount) → Add funds
• withdraw(current_balance, amount) → Withdraw funds if sufficient
• viewTransactions() → Display transaction history
• logTransaction(action) → Save an action in the rolling log
• clearTransactions() → Reset history after logout

Transaction History
• Stores up to 5 actions (deposit, withdraw, check balance).
• Oldest transaction is discarded when limit is reached.

⸻


📚 Extra notes:

Through this project, we've practiced:
• C fundamentals (loops, conditionals, arrays, functions)
• Structs for modeling user accounts
• String manipulation with strcpy, strcmp, sprintf
• Input handling & validation
• Designing a menu-driven program


### Conclusion:

This ATM simulator is a simple, interactive project showcasing how C can be used to model real-world systems.
It’s ideal for beginners learning C programming and practicing program design, user input handling, and data storage in memory.