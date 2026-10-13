# legacy/

Files kept for reference. **None of these are part of the build** — the build
only compiles `src/` (see `build.bat` / `RouteBank.vcxproj`).

Everything here is preserved in git history too, so deleting this folder loses
nothing.

---

## `files.h`

An early second declaration of `class FilesHelper`, never `#include`d by
anything. It declares a different `FilesHelper` interface (`savelastid`,
`getlastid`, `saveEmployee(Employee, string, string)`, …) from the one in
`src/io/FilesHelper.h` that the program actually uses.

Note the two declarations would have collided if any translation unit had
included both — which is presumably why this one was abandoned.

## `Header1.h`

Not a header: a `.cpp` body saved with a `.h` extension (its first line is the
comment `//parser .cpp`). It contains definitions of `Parser::split`,
`Parser::parse_to_client`, `Parser::parse_to_Employee` and `Parser::parse_to_Admin`
— the same functions that now live in `src/io/Parser.cpp`, which is the version
the build uses. It also has an unbalanced `}` at the end.

It was never `#include`d by anything.

## `Header2.h`

Same story — first line is `//data files`. It is an older draft of
`FilesHelper` that **does not compile**: it uses `c.getid << file()` where a
stream insertion was intended, writes to `ofstream file` while trying to read,
calls an undeclared `savelast(...)`, and is missing semicolons throughout.

Also never `#include`d.

## `vs-solution-old/`

A Visual Studio project (`Route_Bank_System.vcxproj`) and its `.slnx`, together
with the older, partial copy of the sources they referenced.

These sources are a strictly earlier version of the same classes: they are
missing `AdminManager`, `ClientManager`, `EmployeeManager`, `Screens`,
`Parser`, `Validate`, `FilesHelper` and `FileManager` entirely, and the files
they do share are thinner — for example `Person.cpp` here is 968 bytes against
911 at the time of the reorganisation, and the `Client`/`Admin`/`Employee`
classes lack the manager layer they later gained.

Their `main.cpp` is not the application entry point: it is a test harness that
prints a client list and a sample deposit. The two `.exe` files kept in this
folder were produced from it.

**This project cannot build the current application.** For the supported Visual
Studio build use `RouteBank.slnx` in the repository root, which compiles
`src/**/*.cpp`.
