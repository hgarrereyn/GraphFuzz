
clang -g \
    $1 \
    -liowow -fsanitize=address \
    -o out
