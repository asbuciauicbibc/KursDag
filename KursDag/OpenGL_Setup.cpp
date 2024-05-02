#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <iostream>
#include <corecrt_math_defines.h>

// ���������� ������
float t = -1.0f;
float rocketX;
float rocketY;
int i = 0;
// �������� ������
const float rocketVelocity = 0.0005f;

// ������� ������
const float screenBottom = -7.5f;
const float screenTop = 7.5f;

// ������� ��� ���������� ������� ������
void updateRocketPosition() {

    // ����������� ����������� ������ �� ������� ������� ������
    /*if (t == 3.0f) {
        rocketY = 0.0f; // ����������� ������ � ������ ������� ������
        rocketX = 3.0f;
    }*/
    if (i == 0) {
        t += rocketVelocity;
        rocketX = t;
        rocketY = -(t * t) + 0,0003 * t;
        std::cout << rocketY;
    }
}

// ������� ��� ��������� ������
void drawRocket() {
    glPushMatrix(); // ���������� ������� ������� ������
    glTranslatef(rocketX, rocketY, 0.0f); // ����������� � ������� ������

    glColor3f(1.0f, 0.0f, 0.0f); // ��������� �������� �����

    glBegin(GL_TRIANGLES); // ������ ��������� ������������ (������)
    glVertex2f(-0.05f, 0.05f); // ������� ������������ (������� ����� ������)
    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.0f, -0.05f); // ������� ������������ (������ ����� ������)
    glEnd(); // ����� ��������� ������������

    glPopMatrix(); // �������������� ���������� ������� ������
}

// ������� ��������� �����
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // ������� ������ �����
    glLoadIdentity(); // ����� ������ ������ � ����

    drawRocket(); // ��������� ������
    updateRocketPosition(); // ���������� ������� ������

    glutSwapBuffers(); // ����� �������� ��� �������� �����������
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // ������������� GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ��������� ������ ������� ����������� � RGB ��������� ������
    glutInitWindowSize(1900, 1600); // ��������� ������� ����
    glutCreateWindow("Rocket Simulation"); // �������� ����

    glewInit(); // ������������� GLEW (��������� ���������� OpenGL)

    glOrtho(-10.0, 10.0, screenBottom, screenTop, -1.0, 1.0); // ��������� ��������������� ��������

    glutDisplayFunc(display); // ����������� ������� ���������
    glutIdleFunc(display); // ����������� �������, ���������� ��� �����������

    glutMainLoop(); // ������ �������� ����� GLUT

    return 0;
}