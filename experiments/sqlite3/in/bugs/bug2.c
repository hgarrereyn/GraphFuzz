

#include "sqlite3.h"

int main() {
    sqlite3 *d1;
    sqlite3 *d2;
    sqlite3 *d3;
    sqlite3_open(":memory:", &d1);
    sqlite3_open(":memory:", &d2);
    sqlite3_open(":memory:", &d3);
    sqlite3_backup *b1 = sqlite3_backup_init(d3, "main", d2, "main");
    sqlite3_backup *b2 = sqlite3_backup_init(d1, "main", d3, "main");
    sqlite3_backup *b3 = sqlite3_backup_init(d1, "main", d2, "main");
    sqlite3_backup_step(b1, 8388608);
    sqlite3_backup_finish(b1);
    sqlite3_backup_step(b2, 0);
    sqlite3_backup_finish(b3);
    sqlite3_backup_step(b2, 8421376); // SEGV
    sqlite3_backup_finish(b2);
    sqlite3_close(d1);
    sqlite3_close(d2);
    sqlite3_close(d3);
}
