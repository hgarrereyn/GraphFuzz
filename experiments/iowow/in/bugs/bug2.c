
#include <iowow/iwkv.h>

int main() {
    IWKV kv;
    IWKV_OPTS opts = {
        .path = "test.db",
        .oflags = IWKV_TRUNC
    };
    (void)iwkv_open(&opts, &kv);
    IWDB db;
    uint32_t id;
    (void)iwkv_new_db(kv, IWDB_VNUM64_KEYS, &id, &db);
    IWKV_val key = { .data = "abc", .size = 0 };
    IWKV_cursor cur = 0;
    iwkv_cursor_open(db, &cur, IWKV_CURSOR_EQ, &key);
    iwkv_cursor_close(&cur);
    iwkv_db_destroy(&db);
    iwkv_close(&kv);
}
