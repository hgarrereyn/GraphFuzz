

#include "sqlite3.h"

int main() {
    sqlite3 *db;
    sqlite3_open(":memory:", &db);
    sqlite3_limit(db, SQLITE_LIMIT_LENGTH, 0);

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "SELECT foo", 11, &stmt, 0);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
