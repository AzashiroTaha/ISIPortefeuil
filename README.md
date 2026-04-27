# 💳 ISI Portefeuil

A command-line **electronic wallet / banking application** written in C. Users can register, log in, and manage a bank account with deposit, withdrawal, and transfer operations. Administrators have elevated privileges to manage clients and accounts directly.

---

## ✨ Features

### Client
- Register a new account (with auto-generated ID and account number)
- Log in with a username and hashed password
- Check account balance
- Deposit money
- Withdraw money
- Transfer money to another account by phone number
- Disable own account

### Admin
- Log in to a dedicated admin space
- Create new admin accounts
- Register new clients
- Deposit / withdraw funds on any client account
- Transfer between accounts
- List all registered clients

---

## 🗂️ Project Structure

```
ISIPortefeuil/
├── main.c          # Entry point — main menu and navigation logic
├── function.h      # All structs (CLIENT, ADMIN, Account, DATE) and function declarations
├── function.c      # Core logic: hashing, account operations, file I/O
├── admin.c         # Admin-specific functions (create admin, manage clients)
├── client.c        # Client-specific functions (register, login, profile)
├── suscriber.c     # Account creation logic (getting_account)
├── menu.c          # Menu rendering (main menu, client menu, admin menu)
├── test.c          # Test / scratch file
│
├── accounts.txt    # Flat-file account storage (one account per line)
├── admin_file.txt  # Admin credentials storage
├── client_file.txt # Client credentials storage
├── accounts.bin    # Binary account backup
└── ids_file        # Auto-increment ID counter
```

---

## 🔐 Data Structures

```c
typedef struct { char pr[20], nm[20], login[100], passwd[HASH_LENGTH], tel[20]; int ID_client; } CLIENT;
typedef struct { char pr[20], nm[20], role[20], login[100], passwd[HASH_LENGTH]; int ID_admin; } ADMIN;
typedef struct { char status[100], type[100], tel[100], acc_num[100]; int balance, ceiling; float interest; } Account;
```

Accounts are stored as plain text lines in `accounts.txt` in the format:
```
acc_num type status ceiling balance interest ID_client name tel creation_date
```

Passwords are hashed with a custom lightweight hash function before being written to disk.

---

## 🚀 Getting Started

### Prerequisites

- GCC (or any C compiler)
- Linux / macOS (the app uses `system("clear")` and `system("read ...")` — Windows not supported natively)

### Build

```bash
gcc main.c function.c admin.c client.c suscriber.c menu.c -o portefeuil
```

### Run

```bash
./portefeuil
```

---

## 🗄️ Data Storage

All data is persisted in plain text files — **no database required**:

| File | Contents |
|------|----------|
| `accounts.txt` | All bank accounts |
| `client_file.txt` | Client credentials and profile |
| `admin_file.txt` | Admin credentials and profile |
| `ids_file` | Auto-increment ID counter |
| `accounts.bin` | Binary backup of accounts |

> Make sure these files exist in the same directory as the executable before running.

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|------------|
| Language | C (C99) |
| Storage | Flat text files |
| UI | Terminal CLI with ANSI colors |
| Build | GCC |
| IDE | VS Code |

---

## 👨‍💻 Author
**Abdoulaye Taha DIOUF**

Project developed as part of the coursework at  
**Institut Supérieur en Informatique (ISI)**
