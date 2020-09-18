
#include <iowow/iwkv.h>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

static vector<IWKV *> open_dbs = vector<IWKV *>();
static int curr_id = 0;

IWKV *new_db() {
    string name = std::tmpnam(nullptr);

    IWKV_OPTS opts = {
        .path = name.c_str()
    };

    IWKV *kv;
    kv = (IWKV *)calloc(1, sizeof(IWKV));
    iwrc rc = iwkv_open(&opts, kv);

    open_dbs.push_back(kv);
    return kv;
}

void close_all() {
    for (int i = 0; i < open_dbs.size(); ++i) {
        IWKV *kv = open_dbs[i];
        iwkv_close(kv);
        free(kv);
    }

    open_dbs.clear();
    curr_id = 0;
}

int next_db_id() {
    curr_id += 1;
    return curr_id;
}
