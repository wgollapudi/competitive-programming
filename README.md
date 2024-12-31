# competitive-programming

My competitive programming work

## Structrue
- **`codeforces/`**: Codeforces work
- **`kattis/`**: A (non-complete) set of problems solved as a part of CS311 - CPII at Purdue University.

## Makefile
I don't like `.exe` extensions

- Run `make gitignore` in any directory to find executeable files and add them to `.gitignore`.
    - Recursivly finds and runs `generate_gitignore.sh` on the current directory. This script finds any non-ignored executeable files in the current directory and appends them to `.gitignore`. This enables the makefile to be copied anywhere within the repository and still work.

### Easy Compilation
- `make` and `make all` work as expected, compiling all C++ files in the directory.

write about .gitignore /template workflow
