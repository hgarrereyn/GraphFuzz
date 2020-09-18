
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
    (void)iwkv_new_db(kv, 0, &id, &db);
    iwkv_db_set_meta(db, "hello", 6);
    iwkv_db_destroy(&db);
    iwkv_close(&kv);
}
