#!/usr/bin/sh

# Usage: generate_gitignore.sh <target_directory>
# Generates a .gitignore in the target directory that contains it's executables
# No .gitignore is generated if would be empty
TARGET_DIR="$1"

if [ -z "$TARGET_DIR" ]; then
    printf "\033[31mError: No directory specified.\033[0m\n"
    echo "Usage: $0 <target_directory>"
    exit 1
fi

cd "$TARGET_DIR" || {
    printf "\033[31mError: Failed to cd into '$TARGET_DIR'.\033[0m\n"
    exit 1
}

tmpfile=$(mktemp) || exit 1

find . -type f -executable -print0 > "$tmpfile"

tr '\0' '\n' < "$tmpfile" | while IFS= read -r file; do
    filename="$(basename "$file")"

    case "$filename" in
        *.*) continue ;;
    esac

    relpath="${file#./}"

    if ! grep -qxF "$relpath" .gitignore 2>/dev/null; then
        [ -f .gitignore ] || touch .gitignore
        echo "$relpath" >> .gitignore
        echo "Added '$relpath' to .gitignore"
    fi
done

rm -f "$tmpfile"
