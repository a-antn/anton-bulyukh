#include <array>
#include <clocale>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "pentagon.h"
#include "point.h"
#include "polygon.h"

/**
 * @brief точка входа
 * @return 0 при успехе иначе 1
 */
int main()
{
    std::setlocale(LC_ALL, "Russian");

    try
    {
        std::array<std::pair<double, double>, PentagonVertexCount> coords = { {
            { 10.0,              0.0              },
            {  3.0901699437495,  9.5105651629515  },
            { -8.0901699437495,  5.8778525229247  },
            { -8.0901699437495, -5.8778525229247  },
            {  3.0901699437495, -9.5105651629515  }
        } };

        Pentagon p1(coords);
        std::cout << "Пятиугольник p1: " << p1 << std::endl;
        std::cout << "  Периметр:                    "
                  << p1.GetPerimetr() << std::endl;
        std::cout << "  Площадь:                     "
                  << p1.GetSquare()   << std::endl;
        std::cout << "  Радиус описанной окружности: "
                  << p1.GetRadius()   << std::endl;

        std::array<Point, PentagonVertexCount> verts;
        for (int i = 0; i < PentagonVertexCount; ++i)
        {
            verts[i] = Point(coords[i].first, coords[i].second);
        }
        Pentagon p2(verts);

        std::cout << "p1 == p2 ? "
                  << ((p1 == p2) ? "да" : "нет") << std::endl;

        Polygon* base = &p1;
        std::cout << "Через указатель на Polygon: " << *base << std::endl;

        std::cout << "\nВведите свой пятиугольник."
                  << " Координаты каждой вершины — два числа через пробел."
                  << std::endl;
        Pentagon p3 = Pentagon::ReadFromInput(std::cin);
        std::cout << "Введён пятиугольник: "
                  << Pentagon::ToString(p3) << std::endl;
        std::cout << "  Периметр: " << p3.GetPerimetr() << std::endl;
        std::cout << "  Площадь:  " << p3.GetSquare()   << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "Ошибка при создании пятиугольника: "
                  << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
