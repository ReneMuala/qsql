//
// Created by ReneMuala on 1/5/2025.
//

#include <gtest/gtest.h>
#define ENABLE_QSQL_DEBUG_MODE
#include <qsql/sqlite3/model>

TEST(MODEL, CREATE_DROP)
{
    qql::sqlite3::model<int> Test("test", "test.db3");

    Test.create({"id", "INTEGER", "value", "TEXT"});
    ASSERT_EQ(Test.sql_query, "CREATE TABLE test ( id INTEGER, value TEXT)");

    Test.drop();
    ASSERT_EQ(Test.sql_query,"DROP TABLE test");
}

TEST(MODEL, QUERY_AND_FIND)
{
    qql::sqlite3::model<int> Test("test", "test.db3");

    Test.create({"id", "INTEGER", "value", "TEXT"});

    Test.query("SELECT * FROM test where id = $1 or value like $2", {1, "second"});
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test where id = '1' or value like 'second'");

    Test.find_all();
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test");

    Test.find_all({"value", "second", "id", 1});
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test where  value = 'second' and id = '1'");

    Test.find_where("value = 'first'");
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test WHERE value = 'first'");

    Test.find_where("value = $1", {"first"});
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test WHERE value = 'first'");

    Test.find(1);
    ASSERT_EQ(Test.sql_query, "SELECT * FROM test WHERE id = '1'");

    Test.drop();
}

TEST(MODEL, DELETE)
{
    qql::sqlite3::model<int> Test("test", "test.db3");

    Test.create({"id", "INTEGER", "value", "TEXT"});

    Test.delete_all();
    ASSERT_EQ(Test.sql_query,"DELETE FROM test WHERE id IS NOT NULL");

    Test.delete_where("id = 1");
    ASSERT_EQ(Test.sql_query,"DELETE FROM test WHERE id = 1");

    Test.delete_where("id = $1", {1});
    ASSERT_EQ(Test.sql_query,"DELETE FROM test WHERE id = '1'");

    Test.delete_(1);
    ASSERT_EQ(Test.sql_query,"DELETE FROM test WHERE id = '1'");

    Test.drop();
}

TEST(MODEL, UPDATE)
{
    qql::sqlite3::model<int> Test("test", "test.db3");

    Test.create({"id", "INTEGER", "value", "TEXT"});

    Test.update_all({"value", "new"});
    ASSERT_EQ(Test.sql_query,"UPDATE test SET value = 'new' WHERE id IS NOT NULL");

    Test.update_where("id = 1", {"value","first"});
    ASSERT_EQ(Test.sql_query,"UPDATE test SET  value = 'first' WHERE id = 1");

    Test.update_where("id = $1", {1},{"value", "first"});
    ASSERT_EQ(Test.sql_query, "UPDATE test SET value = '1' WHERE id = 'first'");

    Test.update(1,{"value", "first"});
    ASSERT_EQ(Test.sql_query, "UPDATE test SET value = '1' WHERE id = 'first'");

    Test.drop();
}

TEST(MODEL, INSERT)
{
    qql::sqlite3::model<int> Test("test", "test.db3");

    Test.create({"id", "INTEGER", "value", "TEXT"});

    Test.insert({"id", "1", "value", "first"});
    ASSERT_EQ(Test.sql_query, "INSERT INTO test(id,value)  VALUES('1','first')");

    Test.insert_all({"id", "value"},{"3", "third", "4", "forth"});
    ASSERT_EQ(Test.sql_query, "INSERT INTO test (id,value) VALUES('3','third'),('4','forth')");

    Test.drop();
}



int main(){
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}