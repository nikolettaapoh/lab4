#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <windows.h>


void task27(void);
void task34(void);
void task53(void);
void task90(void);
void task151(void);
void task242(void);
void task89(void);
void task258(void);
void task195(void);
void task186(void);

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    do {
        printf("\nВведіть номер завдання (1-10, 0 - вихід): ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
        case 1: task27(); break;
        case 2: task34(); break;
        case 3: task53(); break;
        case 4: task90(); break;
        case 5: task151(); break;
        case 6: task242(); break;
        case 7: task89(); break;
        case 8: task258(); break;
        case 9: task195(); break;
        case 10: task186(); break;
        case 0: printf("Завершення роботи.\n"); break;
        default: printf("Некоректний вибір! Спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}

// Завдання 27: Дано дійсне число x. Обчислити x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + x^13/13!
void task27(void) {
    printf("\nЗавдання 27 \n");
    double x;
    printf("Введіть дійсне число x: ");
    scanf("%lf", &x);

    double sum = x;
    double term = x;

    for (int k = 1; k <= 6; k++) {
        term = -term * (x * x) / ((2 * k) * (2 * k + 1));
        sum += term;
    }

    printf("Результат S = %.8lf\n", sum);
}

// Завдання 34: Дано натуральне число п та речове число x. Обчислити sin x + sin x2 + ... + sin xп.
void task34(void) {
    printf("\nЗавдання 34 \n");
    int n;
    double x;
    printf("Введіть натуральне число n та дійсне x: ");
    scanf("%d %lf", &n, &x);

    double sum = 0.0;
    double x_pow = 1.0;

    for (int i = 1; i <= n; i++) {
        x_pow *= x;
        sum += sin(x_pow);
    }

    printf("Сума S = %.6lf\n", sum);
}

// Завдання 53: Знайти суму 22 + 23 + 24 + ... + 210 без зведення у ступінь. 
void task53(void) {
    printf("\nЗавдання 53 \n");
    int sum = 0;
    int term = 4; 

    for (int i = 2; i <= 10; i++) {
        sum += term;
        term *= 2;
    }

    printf("Сума 2^2 + 2^3 + ... + 2^10 = %d\n", sum);
}

// Завдання 90:  Дано числа a1, a2, …, a10. Визначити їхнє середнє арифметичне.
void task90(void) {
    printf("\n Завдання 90 \n");
    double sum = 0.0, a;
    printf("Введіть 10 чисел:\n");
    for (int i = 1; i <= 10; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a);
        sum += a;
    }

    printf("Середнє арифметичне: %.4lf\n", sum / 10.0);
}

// Завдання 151:   Є фрагмент програми у вигляді інструкції циклу з параметром, що забезпечує виведення на екран «стовпчиком» квадратного коріння з усіх цілих чисел від a до b(a > b).Оформити цей фрагмент у вигляді : а) інструкції циклу з передумовою; б) інструкції циклу з постумовою.
void task151(void) {
    printf("\nЗавдання 151 \n");
    int a, b;
    printf("Введіть a та b (де a > b): ");
    scanf("%d %d", &a, &b);

    printf("\nа) Цикл while :\n");
    int i = a;
    while (i >= b) {
        if (i >= 0) {
            printf("sqrt(%d) = %.4lf\n", i, sqrt(i));
        }
        else {
            printf("sqrt(%d) - не існує в дійсних числах\n", i);
        }
        i--;
    }

    printf("\nб) Цикл do-while :\n");
    i = a;
    if (a >= b) {
        do {
            if (i >= 0) {
                printf("sqrt(%d) = %.4lf\n", i, sqrt(i));
            }
            else {
                printf("sqrt(%d) - не існує в дійсних числах\n", i);
            }
            i--;
        } while (i >= b);
    }
}

// Завдання 242: F(x) = x^2 * sin^2 x + 1
void task242(void) {
    printf("\nЗавдання 242 \n");
    double a, b, h;
    printf("Введіть початок відрізка a, кінець b та крок h: ");
    scanf("%lf %lf %lf", &a, &b, &h);

    printf("\n  x\t |   F(x)\n");
    printf("---------------------\n");

    for (double x = a; x <= b + h / 2.0; x += h) {
        double sin_val = sin(x);
        double F = x * x * sin_val * sin_val + 1.0;
        printf("%8.4lf | %8.4lf\n", x, F);
    }
}

// Завдання 89: Дано натуральне число п та речові числа a1,а2...аn. Визначити суму квадратів цих чисел.
void task89(void) {
    printf("\nЗавдання 89 \n");
    int n;
    printf("Введіть кількість чисел n: ");
    scanf("%d", &n);

    double sum_sq = 0.0, a;
    for (int i = 1; i <= n; i++) {
        printf("Введіть число a[%d]: ", i);
        scanf("%lf", &a);
        sum_sq += a * a;
    }

    printf("Сума квадратів: %.4lf\n", sum_sq);
}

// Завдання 258: . Написати програму обчислення функції y = 3.2 * a * b * x^2 - (5 * a * sqrt(1 + 2 * cos^3(x^2))) / (4 * a * x - b) в a = 2; b = 4.Аргумент x приймає значення : -5, -4, -3, -2, 0, 4, 7, 10.
void task258(void) {
    printf("\nЗавдання 258 \n");
    double a = 2.0, b = 4.0;
    int x_values[] = { -5, -4, -3, -2, 0, 4, 7, 10 };
    int count = sizeof(x_values) / sizeof(x_values[0]);

    printf("a = %.1lf, b = %.1lf\n", a, b);
    printf("  x\t |   y\n");
    printf("---------------------\n");

    for (int i = 0; i < count; i++) {
        double x = x_values[i];
        double denom = 4.0 * a * x - b;
        double rad_expr = 1.0 + 2.0 * pow(cos(x * x), 3);

        if (denom == 0) {
            printf("%4.0lf\t | Ділення на 0\n", x);
        }
        else if (rad_expr < 0) {
            printf("%4.0lf\t | Підкореневе число < 0\n", x);
        }
        else {
            double y = 3.2 * a * b * x * x - (5.0 * a * sqrt(rad_expr)) / denom;
            printf("%4.0lf\t | %10.4lf\n", x, y);
        }
    }
}

// Завдання 195: Підробляючи вечорами кур'єром, студент вирішив накопичити суму в С гривень на купівлю комп'ютера. Першого  місяця він відклав Р гривень.Потім його внесок щоразу був на 5 % більший за попередній вклад.Через скільки місяців школяр зможе придбати комп'ютер? Величини Р і С задавати введенням із клавіатури. 
void task195(void) {
    printf("\nЗавдання 195 \n");
    double P, C;
    printf("Введіть початковий внесок P та необхідну суму C: ");
    scanf("%lf %lf", &P, &C);

    double total_sum = 0.0;
    double current_p = P;
    int months = 0;

    while (total_sum < C) {
        months++;
        total_sum += current_p;
        current_p *= 1.05;
    }

    printf("Необхідна кількість місяців: %d\n", months);
    printf("Підсумкова накопичена сума: %.2lf грн\n", total_sum);
}


// Завдання 186: Дано число a ((1 < a <= 1.5). Серед чисел 1 + 1/2, 1 + 1/3, ... знайти перше, менше a. 
void task186(void) {
    printf("\nЗавдання 186 \n");
    double a;
    printf("Введіть число a (1 < a <= 1.5): ");
    scanf("%lf", &a);

    int n = 2;
    double val = 1.0 + 1.0 / n;

    while (val >= a) {
        n++;
        val = 1.0 + 1.0 / n;
    }

    printf("Перше число, менше за %.4lf: %.6lf (при n = %d)\n", a, val, n);
}