#ifndef CONSOLE_COLORS_H
#define CONSOLE_COLORS_H

#ifdef _WIN32

#define COLOR_RED		0x0004
#define COLOR_GREEN		0x0002
#define COLOR_BLUE		0x0001

#define COLOR_WHITE		(COLOR_RED | COLOR_GREEN | COLOR_BLUE)

#define AXIS_X_COLOR	COLOR_RED
#define AXIS_Y_COLOR	COLOR_GREEN
#define AXIS_Z_COLOR	COLOR_BLUE

#endif  _WIN32

#endif  !CONSOLE_COLORS_H
