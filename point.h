#pragma once

#include <iostream>
#include <string>

/**
 * @brief Класс точки на плоскости
 */
class Point {
    private:
        /**
         * @brief абсцисса
         */
        double x;

        /**
         * @brief ордината
         */
        double y;

    public:
        /**
         * @brief конструктор
         * @param x абсцисса
         * @param y ордината
         */
        Point(const double x = 0.0, const double y = 0.0);

        /**
         * @brief получить абсциссу
         * @return значение x
         */
        double GetX() const;

        /**
         * @brief получить ординату
         * @return значение y
         */
        double GetY() const;

        /**
         * @brief расстояние до другой точки
         * @param other вторая точка
         * @return евклидово расстояние
         */
        double DistanceTo(const Point& other) const;

        /**
         * @brief сериализация в строку
         * @return строка вида "(x; y)"
         */
        std::string ToString() const;

        /**
         * @brief равенство
         * @param other вторая точка
         * @return true если координаты совпадают
         */
        bool operator==(const Point& other) const;

        /**
         * @brief неравенство
         * @param other вторая точка
         * @return true если координаты различаются
         */
        bool operator!=(const Point& other) const;

        /**
         * @brief сравнение «меньше»
         * @param other вторая точка
         * @return true если текущая точка меньше other
         */
        bool operator<(const Point& other) const;

        /**
         * @brief сравнение «больше»
         * @param other вторая точка
         * @return true если текущая точка больше other
         */
        bool operator>(const Point& other) const;

        /**
         * @brief сравнение «меньше или равно»
         * @param other вторая точка
         * @return true если текущая точка меньше или равна other
         */
        bool operator<=(const Point& other) const;

        /**
         * @brief сравнение «больше или равно»
         * @param other вторая точка
         * @return true если текущая точка больше или равна other
         */
        bool operator>=(const Point& other) const;

        /**
         * @brief вывод в поток
         * @param out выходной поток
         * @param p точка
         * @return ссылка на поток
         */
        friend std::ostream& operator<<(std::ostream& out, const Point& p);

        /**
         * @brief чтение из потока
         * @param in входной поток
         * @param p точка
         * @return ссылка на поток
         */
        friend std::istream& operator>>(std::istream& in, Point& p);
};
