#pragma once

#include <array>
#include <iostream>
#include <string>
#include <utility>

#include "point.h"
#include "polygon.h"

/**
 * @brief число вершин пятиугольника
 */
constexpr int PentagonVertexCount = 5;

/**
 * @brief допуск при сравнении длин сторон
 */
constexpr double PentagonSideTolerance = 1e-6;

/**
 * @brief Класс «Правильный пятиугольник»
 */
class Pentagon : public Polygon {
    private:
        /**
         * @brief вершины в порядке обхода
         */
        std::array<Point, PentagonVertexCount> points;

        /**
         * @brief длина стороны
         */
        double side_length;

        /**
         * @brief проверка точек и вычисление длины стороны
         * @throw std::invalid_argument при некорректных точках
         */
        void ValidateAndComputeSide();

    public:
        /**
         * @brief конструктор из массива точек
         * @param vertices массив вершин
         * @throw std::invalid_argument если точки не образуют правильный пятиугольник
         */
        Pentagon(const std::array<Point, PentagonVertexCount>& vertices);

        /**
         * @brief конструктор из массива пар координат
         * @param coords массив пар (x, y)
         * @throw std::invalid_argument если координаты не образуют правильный пятиугольник
         */
        Pentagon(const std::array<std::pair<double, double>, PentagonVertexCount>& coords);

        /**
         * @brief сериализация в строку
         * @return текстовое представление
         */
        std::string ToString() const override;

        /**
         * @brief расчёт площади
         * @return значение площади
         */
        double GetSquare() const override;

        /**
         * @brief расчёт периметра
         * @return значение периметра
         */
        double GetPerimetr() const override;

        /**
         * @brief расчёт радиуса описанной окружности
         * @return значение радиуса
         */
        double GetRadius() const override;

        /**
         * @brief чтение вершин из потока
         * @param in входной поток
         * @throw std::invalid_argument при некорректных точках
         */
        void Read(std::istream& in) override;

        /**
         * @brief равенство
         * @param other второй пятиугольник
         * @return true если все вершины совпадают
         */
        bool operator==(const Pentagon& other) const;

        /**
         * @brief неравенство
         * @param other второй пятиугольник
         * @return true если хотя бы одна пара вершин различается
         */
        bool operator!=(const Pentagon& other) const;

        /**
         * @brief статическая сериализация
         * @param p пятиугольник
         * @return текстовое представление
         */
        static std::string ToString(const Pentagon& p);

        /**
         * @brief статическое интерактивное чтение из потока
         * @param in входной поток
         * @return готовый объект Pentagon
         * @throw std::invalid_argument при некорректных точках
         */
        static Pentagon ReadFromInput(std::istream& in);
};

/**
 * @brief вывод в поток
 * @param out выходной поток
 * @param p пятиугольник
 * @return ссылка на поток
 */
std::ostream& operator<<(std::ostream& out, const Pentagon& p);
