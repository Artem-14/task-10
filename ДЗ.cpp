#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "RU");

    double god, proiz, pazmech, hran, moshnost;
    std::cout << "Введите годовую потребность (D): ";
    std::cin >> god;
    std::cout << "Введите затраты на запуск производства (S производства): ";
    std::cin >> proiz;
    std::cout << "Введите затраты на размещение заказа (S закупки): ";
    std::cin >> pazmech;
    std::cout << "Введите затраты на хранение единицы на складе (H): ";
    std::cin >> hran;
    std::cout << "Введите мощность производства в день: ";
    std::cin >> moshnost;

    // Расчёт для производства
    double Q_production = sqrt((2 * god * proiz) / hran); // Оптимальный размер партии
    double max_production_capacity = moshnost * 365;     // Годовая мощность производства
    if (Q_production > max_production_capacity) {
        Q_production = max_production_capacity;
        std::cout << "\nПроизводственная мощность ограничила размер партии до " << Q_production << " ед." << std::endl;
    }

    double N_production = god / Q_production; // Число циклов в год
    double C_production = N_production * proiz + (Q_production / 2) * hran; // Общие затраты

    // Расчёт для закупки
    double Q_purchase = sqrt((2 * god * pazmech) / hran); // Оптимальный размер партии
    double N_purchase = god / Q_purchase;                // Число циклов в год
    double C_purchase = N_purchase * pazmech + (Q_purchase / 2) * hran; // Общие затраты

    // Вывод результатов
    std::cout << "\nПроизводство:" << std::endl;
    std::cout << "Оптимальный размер партии: " << Q_production << " ед." << std::endl;
    std::cout << "Число циклов в год: " << N_production << std::endl;
    std::cout << "Общие затраты: " << C_production << " долл." << std::endl;

    std::cout << "\nЗакупка:" << std::endl;
    std::cout << "Оптимальный размер партии: " << Q_purchase << " ед." << std::endl;
    std::cout << "Число циклов в год: " << N_purchase << std::endl;
    std::cout << "Общие затраты: " << C_purchase << " долл." << std::endl;

    // Сравнение вариантов
    if (C_production < C_purchase) {
        std::cout << "\nВыгоднее производить изделия на фирме." << std::endl;
    }
    else {
        std::cout << "\nВыгоднее закупать изделия у подрядчика." << std::endl;
    }

    return 0;
}

// Сначала начал писать сам, а в итоге пришлось обратиться к gpt, так как не понимал по какой формуле считать. В остальном код простой, могу написать сам.
