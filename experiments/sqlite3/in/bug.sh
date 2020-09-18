
clang -g \
    $1 \
    sqlite3.c \
    -I. -ldl -lpthread -fsanitize=address \
    -o out
