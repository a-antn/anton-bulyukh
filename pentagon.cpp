#include <cmath>
#include <numbers>
#include <sstream>
#include <stdexcept>

#include "pentagon.h"

void Pentagon::ValidateAndComputeSide()
{
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        for (int j = i + 1; j < PentagonVertexCount; ++j)
        {
            if (points[i] == points[j])
            {
                throw std::invalid_argument(
                    "Pentagon: совпадающие вершины недопустимы");
            }
        }
    }

    double first_side = points[0].DistanceTo(points[1]);
    if (first_side <= 0.0)
    {
        throw std::invalid_argument(
            "Pentagon: длина стороны должна быть положительной");
    }

    for (int i = 1; i < PentagonVertexCount; ++i)
    {
        int next = (i + 1) % PentagonVertexCount;
        double side = points[i].DistanceTo(points[next]);
        if (std::fabs(side - first_side) > PentagonSideTolerance)
        {
            throw std::invalid_argument(
                "Pentagon: стороны должны быть равны");
        }
    }

    side_length = first_side;
}

Pentagon::Pentagon(const std::array<Point, PentagonVertexCount>& vertices)
    : points{vertices}, side_length{0.0}
{
    ValidateAndComputeSide();
}

Pentagon::Pentagon(const std::array<std::pair<double, double>, PentagonVertexCount>& coords)
    : points{}, side_length{0.0}
{
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        points[i] = Point(coords[i].first, coords[i].second);
    }
    ValidateAndComputeSide();
}

std::string Pentagon::ToString() const
{
    std::ostringstream oss;
    oss << "Pentagon { сторона = " << side_length << ", вершины: ";
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        oss << points[i].ToString();
        if (i + 1 < PentagonVertexCount)
        {
            oss << ", ";
        }
    }
    oss << " }";
    return oss.str();
}

double Pentagon::GetSquare() const
{
    return 0.25 * std::sqrt(5.0 * (5.0 + 2.0 * std::sqrt(5.0)))
        * side_length * side_length;
}

double Pentagon::GetPerimetr() const
{
    return PentagonVertexCount * side_length;
}

double Pentagon::GetRadius() const
{
    return side_length / (2.0 * std::sin(std::numbers::pi / PentagonVertexCount));
}

void Pentagon::Read(std::istream& in)
{
    std::array<Point, PentagonVertexCount> buffer;
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        in >> buffer[i];
    }

    points = buffer;
    ValidateAndComputeSide();
}

bool Pentagon::operator==(const Pentagon& other) const
{
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        if (points[i] != other.points[i])
        {
            return false;
        }
    }
    return true;
}

bool Pentagon::operator!=(const Pentagon& other) const
{
    return !(*this == other);
}

std::string Pentagon::ToString(const Pentagon& p)
{
    return p.ToString();
}

Pentagon Pentagon::ReadFromInput(std::istream& in)
{
    std::array<Point, PentagonVertexCount> buffer;
    for (int i = 0; i < PentagonVertexCount; ++i)
    {
        std::cout << "Введите координаты вершины #" << (i + 1)
                  << " (x y): ";
        in >> buffer[i];
    }
    return Pentagon(buffer);
}

std::ostream& operator<<(std::ostream& out, const Pentagon& p)
{
    out << p.ToString();
    return out;
}
