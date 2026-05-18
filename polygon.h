#pragma once

#include <iostream>
#include <string>

#include "point.h"

/**
 * @brief Абстрактный класс «Правильный многоугольник»
 */
class Polygon {
    public:
        /**
         * @brief виртуальный деструктор
         */
        virtual ~Polygon() = default;

        /**
         * @brief сериализация в строку
         * @return текстовое представление
         */
        virtual std::string ToString() const = 0;

        /**
         * @brief расчёт площади
         * @return значение площади
         */
        virtual double GetSquare() const = 0;

        /**
         * @brief расчёт периметра
         * @return значение периметра
         */
        virtual double GetPerimetr() const = 0;

        /**
         * @brief расчёт радиуса описанной окружности
         * @return значение радиуса
         */
        virtual double GetRadius() const = 0;

        /**
         * @brief чтение из потока
         * @param in входной поток
         */
        virtual void Read(std::istream& in) = 0;
};

/**
 * @brief вывод в поток
 * @param out выходной поток
 * @param p многоугольник
 * @return ссылка на поток
 */
std::ostream& operator<<(std::ostream& out, const Polygon& p);

/**
 * @brief чтение из потока
 * @param in входной поток
 * @param p многоугольник
 * @return ссылка на поток
 */
std::istream& operator>>(std::istream& in, Polygon& p);
