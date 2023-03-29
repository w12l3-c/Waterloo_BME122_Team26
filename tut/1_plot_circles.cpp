// BME 122 Tutorial 1 Example
// Plot Circles
// Plots a user inputted number of circles

#include <iostream>
#include <cmath>

using namespace std;

// Constants to control plot size
const int WIDTH = 50;
const int HEIGHT = 25;

// Constant to control vertical scale
// Corrects for characters being taller than they are wide
const float Y_STRETCH_FACTOR = 0.5;

// Constants to define chars used in plot
const char FG_CHAR = '*';
const char BG_CHAR = ' ';
const char BORDER_CHAR = '#';

// Class definitions (these are often in their own files)

// A circle
// Has a location (x, y) and a radius
class Circle {
  public:
    Circle(int x, int y, int r); // Constructor
    int x_pos, y_pos, radius;
};

// A plot
// Circles can be added and the plot can be displayed
class Plot {
  public:
    void addCircle(Circle circle);
    void display();
  private:
    bool plot[HEIGHT][WIDTH] = {};
};

int main() {
  Plot plot;
  int num_circles, x, y, r;

  cout << "How many circles do you want to draw? ";
  cin >> num_circles;
  cout << endl;

  for (int i = 1; i <= num_circles; i++) {
    cout << "Circle " << i << " x-position: ";
    cin >> x;

    cout << "Circle " << i << " y-position: ";
    cin >> y;

    cout << "Circle " << i << " radius: ";
    cin >> r;

    Circle circle(x, y, r);
    plot.addCircle(circle);

    cout << endl;
  }

  plot.display();
}

// Function definitions

// Circle constructor
Circle::Circle(int x, int y, int r) : x_pos(x), y_pos(y), radius(r) {
  //Deliberately left empty
}

// Adds a circle to the plot
// Part of the plot class
void Plot::addCircle(Circle circle) {
  int y_pos, y_offset, x_start, x_end;

  // Find the y-position of the circle after applying the stretch factor
  y_pos = round(circle.y_pos * Y_STRETCH_FACTOR);

  // Find the left-most and right-most x-positions of the circle
  x_start = circle.x_pos - circle.radius;
  x_end = circle.x_pos + circle.radius;

  // Ensure x-positions are in the plot
  if (x_start < 0)
    x_start = 0;
  if (x_end > WIDTH - 1)
    x_end = WIDTH - 1;

  // For each x-position in the circle
  for (int x = x_start; x <= x_end; x++) {
    // Find y_position's offset from centre
    // Recall the formula for a circle (x-u)^2 - (y-v)^2 = r^2
    // We also adjust by the stretch factor and round to the nearest integer
    y_offset = round(
      sqrt(pow(circle.radius, 2) - pow(x - circle.x_pos, 2)) * Y_STRETCH_FACTOR
    );

    // Add top and bottom of circle to the plot
    // Check the position is on the plot before adding
    if (y_pos + y_offset < HEIGHT)
      plot[y_pos + y_offset][x] = true;
    if (y_pos - y_offset >= 0)
      plot[y_pos - y_offset][x] = true;
  }
}

// Function that prints the plot
// Part of the plot class
void Plot::display() {
  // Draw top of border
  for (int x = 0; x < WIDTH + 2; x++)
    cout << BORDER_CHAR;
  cout << endl;

  // Draw plot (and sides of border)
  // y decreases at iteration as the highest y values are at the top of the plot
  for (int y = HEIGHT - 1; y >= 0; y--) {
    cout << BORDER_CHAR;
    for (int x = 0; x < WIDTH; x++) {
      if (plot[y][x])
        cout << FG_CHAR;
      else
        cout << BG_CHAR;
    }
    cout << BORDER_CHAR << endl;
  }

  // Draw bottom of border
  for (int x = 0; x < WIDTH + 2; x++)
    cout << BORDER_CHAR;
  cout << endl;
}
