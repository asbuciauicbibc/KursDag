#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <iostream>
#include <corecrt_math_defines.h>

// Координаты ракеты
float t = -1.0f;
float rocketX;
float rocketY;
int i = 0;
// Скорость ракеты
const float rocketVelocity = 0.0005f;

// Границы экрана
const float screenBottom = -7.5f;
const float screenTop = 7.5f;

// Функция для обновления позиции ракеты
void updateRocketPosition() {

    // Ограничение перемещения ракеты за верхнюю границу экрана
    /*if (t == 3.0f) {
        rocketY = 0.0f; // Возвращение ракеты к нижней границе экрана
        rocketX = 3.0f;
    }*/
    if (i == 0) {
        t += rocketVelocity;
        rocketX = t;
        rocketY = -(t * t) + 0,0003 * t;
        std::cout << rocketY;
    }
}

// Функция для отрисовки ракеты
void drawRocket() {
    glPushMatrix(); // Сохранение текущей матрицы модели
    glTranslatef(rocketX, rocketY, 0.0f); // Перемещение в позицию ракеты

    glColor3f(1.0f, 0.0f, 0.0f); // Установка красного цвета

    glBegin(GL_TRIANGLES); // Начало отрисовки треугольника (ракеты)
    glVertex2f(-0.05f, 0.05f); // Вершина треугольника (верхняя часть ракеты)
    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.0f, -0.05f); // Вершина треугольника (нижняя часть ракеты)
    glEnd(); // Конец отрисовки треугольника

    glPopMatrix(); // Восстановление предыдущей матрицы модели
}

// Функция отрисовки сцены
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Очистка буфера цвета
    glLoadIdentity(); // Сброс матриц модели и вида

    drawRocket(); // Отрисовка ракеты
    updateRocketPosition(); // Обновление позиции ракеты

    glutSwapBuffers(); // Обмен буферами для плавного отображения
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Инициализация GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Установка режима двойной буферизации и RGB цветового режима
    glutInitWindowSize(1900, 1600); // Установка размера окна
    glutCreateWindow("Rocket Simulation"); // Создание окна

    glewInit(); // Инициализация GLEW (Обработка расширений OpenGL)

    glOrtho(-10.0, 10.0, screenBottom, screenTop, -1.0, 1.0); // Установка ортографической проекции

    glutDisplayFunc(display); // Регистрация функции отрисовки
    glutIdleFunc(display); // Регистрация функции, вызываемой при бездействии

    glutMainLoop(); // Запуск главного цикла GLUT

    return 0;
}