
extern "C" {
    #include "sqlite3.h"
}

#include <vector>

using namespace std;

static vector<sqlite3 *> open_dbs = vector<sqlite3 *>();

sqlite3 *new_database() {
    sqlite3 *db;
    sqlite3_open(":memory:", &db);

    open_dbs.push_back(db);
    return db;
}

void close_all() {
    for (int i = 0; i < open_dbs.size(); ++i) {
        sqlite3 *db = open_dbs[i];
        sqlite3_close(db);
    }

    open_dbs.clear();
}
