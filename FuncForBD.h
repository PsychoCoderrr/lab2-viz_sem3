#pragma once
#include <mysqlx/xdevapi.h>

void addToBD(int type, int size, double& time)
{
    try {
        // Создание сессии
        mysqlx::Session session("localhost", 33060, "root", "1234");

        // Подключение к схеме (базе данных)
        mysqlx::Schema schema = session.getSchema("sorting_db");

        // Доступ к таблице
        mysqlx::Table table = schema.getTable("sorting_results");

        // Вставка данных
        table.insert("sort_type", "array_size", "execution_time")
            .values(type, size, time)
            .execute();
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    } catch (std::exception &ex) {
        std::cerr << "STD Exception: " << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }
}
