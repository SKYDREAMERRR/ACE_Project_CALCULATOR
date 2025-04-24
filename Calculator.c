#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function declarations
float area_circle(float radius);
float circumference_circle(float radius);

float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);

float area_triangle(float a, float b, float c);
float perimeter_triangle(float a, float b, float c);

float get_positive_input(const char *prompt);

int main() {
    int choice;

    do {
        printf("\n=== Geometry Calculator ===\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Choose a shape (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float radius = get_positive_input("Enter radius of the circle: ");
                printf("Area of Circle: %.2f\n", area_circle(radius));
                printf("Circumference of Circle: %.2f\n", circumference_circle(radius));
                break;
            }
            case 2: {
                float length = get_positive_input("Enter length of the rectangle: ");
                float width = get_positive_input("Enter width of the rectangle: ");
                printf("Area of Rectangle: %.2f\n", area_rectangle(length, width));
                printf("Perimeter of Rectangle: %.2f\n", perimeter_rectangle(length, width));
                break;
            }
            case 3: {
                float a = get_positive_input("Enter side a of the triangle: ");
                float b = get_positive_input("Enter side b of the triangle: ");
                float c = get_positive_input("Enter side c of the triangle: ");

                // Check if sides form a valid triangle
                if (a + b > c && a + c > b && b + c > a) {
                    printf("Area of Triangle: %.2f\n", area_triangle(a, b, c));
                    printf("Perimeter of Triangle: %.2f\n", perimeter_triangle(a, b, c));
                } else {
                    printf("Invalid triangle sides!\n");
                }
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function Definitions
float area_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

// Heron's formula for triangle area
float area_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

// Input function with validation
float get_positive_input(const char *prompt) {
    float value;
    do {
        printf("%s", prompt);
        scanf("%f", &value);
        if (value <= 0) {
            printf("Value must be positive. Try again.\n");
        }
    } while (value <= 0);
    return value;
}
