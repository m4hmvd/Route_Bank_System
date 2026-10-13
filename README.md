# Route Bank System

A console banking management application written in C++. It simulates a small
bank with three distinct roles — **Client**, **Employee** and **Admin** — each
with its own login and menu, persisting everything to plain text files instead
of a database.

<p align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square" alt="C++"/>
  <img src="https://img.shields.io/badge/standard-C%2B%2B17-00599C?style=flat-square" alt="C++17"/>
  <img src="https://img.shields.io/badge/platform-Windows-0078D4?style=flat-square" alt="Windows"/>
  <img src="https://img.shields.io/badge/course-Fundamentals%20of%20Programming-informational?style=flat-square" alt="Course"/>
</p>

---

## Contents

- [Features](#features)
- [Project structure](#project-structure)
- [Architecture](#architecture)
- [Building](#building)
- [Running](#running)
- [Demo accounts](#demo-accounts)
- [Data and persistence](#data-and-persistence)
- [Known limitations](#known-limitations)
- [Course information](#course-information)

---

## Features

**Role-based modules**

- **Client** — check balance, deposit, withdraw, instant and scheduled transfers,
  request a loan, change password, view transaction history and account progress.
- **Employee** — check salary, activate or deactivate client accounts, change a
  client's password, count/search/list clients, add clients, view a client's balance.
- **Admin** — system statistics, risk assessment of a client, hire and list
  employees, adjust employee salaries, search employees.

**Persistence** — everything is stored in `&`-separated plain text files under
`data/`. There is no database and no external dependency; the files are loaded
at startup and written back as operations complete.

**Console UI** — a splash screen, centred text, a boxed main menu, coloured
output and a signing-off screen.

---

## Project structure

```
Route_Bank_System/
├── build.bat              Windows / MSVC build script
├── RouteBank.slnx         Visual Studio solution
├── RouteBank.vcxproj      Visual Studio project
├── data/                  the text "database" (loaded at startup)
│   ├── Clients.txt
│   ├── Employees.txt
│   ├── Admins.txt
│   └── *_Last_ID.txt      auto-increment counters
├── src/
│   ├── main.cpp           entry point -> runapp()
│   ├── model/             domain classes
│   ├── managers/          one console module per role
│   ├── io/                persistence, parsing, validation
│   └── ui/                menus and console helpers
└── legacy/                abandoned drafts, kept for reference only
```

`legacy/` is **not** compiled. See [`legacy/README.md`](legacy/README.md) for
what is in there and why it was set aside.

---

## Architecture

Four layers, each only depending on the ones below it.

| Layer | Folder | Classes |
|---|---|---|
| **Model** | `src/model/` | `Person` (abstract) → `Client`, `Employee` → `Admin`; plus `Transaction`, `TimeOfDay` |
| **Managers** | `src/managers/` | `ClientManager`, `EmployeeManager`, `AdminManager` — one console workflow per role |
| **I/O** | `src/io/` | `FilesHelper`, `FileManager`, `Parser`, `Validate`, `DataPaths`, `DataSourceInterface` |
| **UI** | `src/ui/` | `Screens` — splash screen, main menu, routing, colour helpers |

Notable details:

- `Client`, `Employee` and `Admin` all derive from `Person`, which holds the
  `id`, `name` and `password` and declares the pure virtual `turn_on()`.
- Both `Client` and `Employee` each keep their own **static** counters and totals
  (`client_counter`, `total_balances`, `employee_counter`, `total_salaries`, …).
- Reading a record back from disk goes through a private constructor reserved for
  `Parser`, which is declared a `friend` of the model classes — that is why
  `friend class Parser;` appears on each of them.
- `TimeOfDay` is a small time-of-day value type used to timestamp transactions
  and to decide whether a scheduled transfer is inside the allowed window
  (12:00–23:59).

> `src/io/FileManager.*` and `src/io/DataSourceInterface.h` describe a cleaner
> storage abstraction but are **not currently wired in** — nothing instantiates
> `FileManager`. They are kept because they document the intended direction.

---

## Building

Windows only (see [Known limitations](#known-limitations)). You need the
**MSVC** toolchain — the free [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/)
with the *Desktop development with C++* workload are enough; the full IDE is not required.

### With the build script (recommended)

From the project root:

```bat
build.bat
```

The script locates the toolchain itself (via `vswhere`), compiles every `.cpp`
under `src/`, and writes `build\RouteBank.exe`. To build and immediately run:

```bat
build.bat run
```

### With Visual Studio

Open `RouteBank.slnx` and build. The project globs `src\**\*.cpp`, so files you
add under `src/` are picked up without editing the project.

### Manually

From a *Developer Command Prompt for VS*, at the project root:

```bat
cl /nologo /std:c++17 /EHsc /I"src" /I"src\model" /I"src\managers" /I"src\io" /I"src\ui" /Fe:build\RouteBank.exe src\*.cpp src\model\*.cpp src\managers\*.cpp src\io\*.cpp src\ui\*.cpp
```

All source files are included flat (`#include "Client.h"`), and the compiler is
pointed at each source folder with `-I`. That keeps the includes short without
putting every file in one directory.

---

## Running

Run **from the project root**, so that the `data/` folder is found:

```bat
build\RouteBank.exe
```

`src/io/DataPaths.*` resolves every data file name, preferring `data/<name>`.
If the program is started somewhere else — an unpacked copy where the `.txt`
files sit next to the executable — those files are used instead, so that layout
still works. If neither exists, `data/` is created and the file is treated as new.

The startup sequence is a splash screen, then the main menu:

```
(1) Client Module
(2) Employee Module
(3) Admin Module
(4) Exit
```

---

## Demo accounts

The `data/` files ship with sample accounts so the program is usable
immediately. **These are demo credentials for a coursework project — see
[Known limitations](#known-limitations).**

| Role | ID | Password |
|---|---|---|
| Client | `2400000` | `RealMad15?` |
| Client | `2400001` | `FCBarca5!` |
| Employee | `2100001` | `Java<<555` |
| Employee | `2100000` | `Ahlawy72%` |
| Admin | `1900000` | `RouteITI25.` |

Admin and Employee modules ask for the ID and password straight away; the Client
module offers a log-in / sign-up menu first.

---

## Data and persistence

The files are line-oriented records with `&` as the separator.

**`Clients.txt`** — `id & name & password & balance & active & loan & risk_counter`

```
2400000&Mostafa&RealMad15?&280000&1&0&0
2400004&Rawan&Roro0000#&50000&1&10000&0
```

**`Employees.txt` / `Admins.txt`** — `id & name & password & salary`

```
2100001&Mahmoud&Java<<555&25000
1900000&Zaki&RouteITI25.&50000
```

The `*_Last_ID.txt` files hold the next id to hand out
(`getNextClientId()`, `getNextEmployeeId()`, `getNextAdminId()` read, increment
and rewrite them). Client ids start at `2400000`, employees at `2100000` and
admins at `1900000`.

Because new accounts are appended and the lists are rewritten in place, **edit
these files only while the program is not running.**

---

## Known limitations

Worth knowing before reading or reusing this code:

- **Windows only.** `src/ui/Screens.cpp` uses `<windows.h>` and
  `SetConsoleTextAttribute` directly for colour, and `system("cls")` to clear the
  screen. The manager modules also include `<windows.h>`. Porting to Linux/macOS
  means replacing the colour and clear-screen helpers with ANSI escape codes.
- **Passwords are stored in plaintext** in the data files and compared as plain
  strings. Fine for a local exercise, not for anything real.
- **`FileManager` is dead code** — see [Architecture](#architecture).
- **Transaction history is a fixed array of 100** per client
  (`Transaction transactions[100]`), so long sessions lose the oldest entries.
- **No EOF handling on input.** If stdin ends while the program is waiting — for
  example in a script with too few lines — the input loop spins instead of
  exiting cleanly.
- **No license file.** If you intend to reuse this, add one.

---

## Course information

| | |
|---|---|
| **Course** | Fundamentals of Programming |
| **Cycle** | 25 |
| **Project** | Route Bank System |

**Team**

- Mostafa Aly Mostafa
- Mahmoud Samir Mahmoud
- Saeed Mohammed Saeed
- Kareem Mahmoud Kamal
- Amr Mohammed Elshabrawy
