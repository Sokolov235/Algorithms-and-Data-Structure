#include <gtest.h>
#include "../lib_HeshMap/HeshMap.h"



// Тесты для целочисленных ключей
TEST(HashTableTest, IntegerKeyInsert) {
    Hesh_table<int, std::string> table;
    int index1 = table.insert(42, "Answer");
    int index2 = table.insert(42 + CAPACITY, "Collision"); // Должно быть коллизия

    EXPECT_EQ(index1, index2);
    EXPECT_EQ(table._size, 2);
}

TEST(HashTableTest, IntegerKeyRetrieve) {
    Hesh_table<int, std::string> table;
    table.insert(1, "One");
    table.insert(2, "Two");

    // Проверяем, что элементы добавлены (косвенно через print)
    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("1") != std::string::npos);
    EXPECT_TRUE(output.find("One") != std::string::npos);
    EXPECT_TRUE(output.find("2") != std::string::npos);
    EXPECT_TRUE(output.find("Two") != std::string::npos);
}

// Тесты для строковых ключей
TEST(HashTableTest, StringKeyInsert) {
    Hesh_table<std::string, int> table;
    int index1 = table.insert("apple", 1);
    int index2 = table.insert("banana", 2);

    EXPECT_NE(index1, index2); // В идеале разные строки должны давать разные хеши
    EXPECT_EQ(table._size, 2);
}

TEST(HashTableTest, StringKeyCollision) {
    Hesh_table<std::string, int> table;
    // Найдем две строки, которые дают одинаковый хеш (маловероятно, но возможно)
    std::string str1 = "collision1";
    std::string str2 = "collision2";

    while (Hesh_function(str1) != Hesh_function(str2)) {
        str2 += "x";
    }

    int index1 = table.insert(str1, 1);
    int index2 = table.insert(str2, 2);

    EXPECT_EQ(index1, index2);
    EXPECT_EQ(table._size, 2);
}

// Тест на обработку неподдерживаемого типа ключа
TEST(HashTableTest, UnsupportedKeyType) {
    struct UnsupportedType {};

    EXPECT_THROW(Hesh_function(UnsupportedType()), std::logic_error);
}

// Тест на производительность (вставка множества элементов)
TEST(HashTableTest, PerformanceTest) {
    Hesh_table<int, int> table;
    const int N = 1000;

    for (int i = 0; i < N; ++i) {
        table.insert(i, i * i);
    }

    EXPECT_EQ(table._size, N);
}

// Тест на пустую таблицу
TEST(HashTableTest, EmptyTable) {
    Hesh_table<int, std::string> table;

    testing::internal::CaptureStdout();
    table.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.empty());
    EXPECT_EQ(table._size, 0);
}
