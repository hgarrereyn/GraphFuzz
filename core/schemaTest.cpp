
#include "schema.hpp"
#include <gtest/gtest.h>


TEST(schema, simple_valid) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "dat *", "id": 0}
            ],
            "scopes": [
                { "name": "init_dat", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "consume_dat", "inputs": [0], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
}

TEST(schema, simple_missing_constructor) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "dat *", "id": 0}
            ],
            "scopes": [
                { "name": "consume_dat", "inputs": [0], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(false, schema.Validate());
}

TEST(schema, simple_missing_destructor) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "dat *", "id": 0}
            ],
            "scopes": [
                { "name": "init_dat", "inputs": [], "outputs": [0], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(false, schema.Validate());
}

TEST(schema, multi_valid) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "dat *", "id": 0}
            ],
            "scopes": [
                { "name": "init_dat", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "init_dat2", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "init_dat3", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "consume_dat", "inputs": [0], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
}

TEST(schema, chain_valid) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1}
            ],
            "scopes": [
                { "name": "make_a", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "a_to_b", "inputs": [0], "outputs": [1], "context": 0 },
                { "name": "del_b", "inputs": [1], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
}

TEST(schema, chain_valid_2) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1},
                {"name": "c", "id": 2}
            ],
            "scopes": [
                { "name": "make_a", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "a_to_b", "inputs": [0], "outputs": [1], "context": 0 },
                { "name": "b_to_a", "inputs": [1], "outputs": [0], "context": 0 },
                { "name": "b_to_c", "inputs": [1], "outputs": [2], "context": 0 },
                { "name": "del_c", "inputs": [2], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
}

TEST(schema, loop_invalid) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1}
            ],
            "scopes": [
                { "name": "a_to_b", "inputs": [0], "outputs": [1], "context": 0 },
                { "name": "b_to_a", "inputs": [1], "outputs": [0], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(false, schema.Validate());
}

TEST(schema, recursive_valid) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1},
                {"name": "c", "id": 2}
            ],
            "scopes": [
                { "name": "init", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "X", "inputs": [2], "outputs": [0], "context": 0 },
                { "name": "A", "inputs": [0], "outputs": [], "context": 0 },
                { "name": "B", "inputs": [0], "outputs": [1], "context": 0 },
                { "name": "C", "inputs": [1], "outputs": [], "context": 0 },
                { "name": "D", "inputs": [1], "outputs": [2], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());

    schema.PrintTypeTree(schema.GetInitializer(0));
    schema.PrintTypeTree(schema.GetInitializer(1));
    schema.PrintTypeTree(schema.GetInitializer(2));

    schema.PrintTypeTree(schema.GetFinalizer(0));
    schema.PrintTypeTree(schema.GetFinalizer(1));
    schema.PrintTypeTree(schema.GetFinalizer(2));

    ASSERT_EQ(1, schema.GetInitializer(0).num_subtrees);
    ASSERT_EQ(1, schema.GetInitializer(1).num_subtrees);
    ASSERT_EQ(1, schema.GetInitializer(2).num_subtrees);

    ASSERT_EQ(2, schema.GetFinalizer(0).num_subtrees);
    ASSERT_EQ(2, schema.GetFinalizer(1).num_subtrees);
    ASSERT_EQ(2, schema.GetFinalizer(2).num_subtrees);
}

TEST(schema, type_id_nonlinear) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 5},
                {"name": "b", "id": 10},
                {"name": "c", "id": 100}
            ],
            "scopes": [
                { "name": "init", "inputs": [], "outputs": [5], "context": 0 },
                { "name": "X", "inputs": [100], "outputs": [5], "context": 0 },
                { "name": "A", "inputs": [5], "outputs": [], "context": 0 },
                { "name": "B", "inputs": [5], "outputs": [10], "context": 0 },
                { "name": "C", "inputs": [10], "outputs": [], "context": 0 },
                { "name": "D", "inputs": [10], "outputs": [100], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());

    schema.PrintTypeTree(schema.GetInitializer(5));
    schema.PrintTypeTree(schema.GetInitializer(10));
    schema.PrintTypeTree(schema.GetInitializer(100));

    schema.PrintTypeTree(schema.GetFinalizer(5));
    schema.PrintTypeTree(schema.GetFinalizer(10));
    schema.PrintTypeTree(schema.GetFinalizer(100));

    ASSERT_EQ(1, schema.GetInitializer(5).num_subtrees);
    ASSERT_EQ(1, schema.GetInitializer(10).num_subtrees);
    ASSERT_EQ(1, schema.GetInitializer(100).num_subtrees);

    ASSERT_EQ(2, schema.GetFinalizer(5).num_subtrees);
    ASSERT_EQ(2, schema.GetFinalizer(10).num_subtrees);
    ASSERT_EQ(2, schema.GetFinalizer(100).num_subtrees);
}

TEST(schema, sqlite3_example) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "sqlite3_stmt *", "id": 0},
                {"name": "sqlite3 *", "id": 1}
            ],
            "scopes": [
                { "name": "sqlite3_open", "inputs": [], "outputs": [1], "context": 0 },
                { "name": "sqlite3_close", "inputs": [1], "outputs": [], "context": 0 },
                { "name": "sqlite3_prepare", "inputs": [1], "outputs": [1,0], "context": 0},
                { "name": "sqlite3_finalize", "inputs": [0], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());
}

TEST(schema, zigzag) {
    Schema schema = Schema::FromString(R"(
        {
            "types": [
                {"name": "a", "id": 0},
                {"name": "b", "id": 1},
                {"name": "c", "id": 2},
                {"name": "d", "id": 3},
                {"name": "e", "id": 4}
            ],
            "scopes": [
                { "name": "z1", "inputs": [], "outputs": [0], "context": 0 },
                { "name": "z2", "inputs": [0,1], "outputs": [], "context": 0 },
                { "name": "z3", "inputs": [], "outputs": [1,2], "context": 0 },
                { "name": "z4", "inputs": [2,3], "outputs": [], "context": 0 },
                { "name": "z5", "inputs": [], "outputs": [3,4], "context": 0 },
                { "name": "z6", "inputs": [4], "outputs": [], "context": 0 }
            ]
        }
    )");

    ASSERT_EQ(true, schema.Validate());

    schema.PrintTypeTree(schema.GetFinalizer(0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
