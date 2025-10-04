#include <stdio.h>
#include <math.h>

    /* @brief Вычисляет значение А по формуле
     * @param x Значение константы x
     * @param y Значение константы y
     * @param z Значение константы z
     * @param e Значение константы e(число эйлера)
     * @return Вычисленное значение А
     */
    double
    GetA(const double x, const double y, const double z);

/* @brief Вычисляет значение B по формуле
 * @param a Значение константы a
 * @param y Значение константы y
 * @param z Значение константы z
 * @param e Значение константы e(число эйлера)
 * @return Вычисленное значение B
 */
double GetB(const double a, const double y, const double z);

/* @brief Точка входа в программу
 * @return 0 В случае успеха
 */
int main(void)
{
    const double x = -0.5;
    const double y = 1.7;
    const double z = 0.44;
    const double a = GetA(x, y, z);
    printf("X: %lf\n", x);
    printf("Y: %lf\n", y);
    printf("Z: %lf\n", z);
    printf("A: %lf\nB: %lf", a, GetB(a, y, z));
    return 0;
}

double GetA(const double x, const double y, const double z)
{
    return exp(-1 * y * z) * sin(x * z - y) - sqrt(fabs(y * z + x));
}

double GetB(const double a, const double y, const double z)
{
    return y * sin(a * pow(z, 2) * cos(2 * z)) - 1;
}

