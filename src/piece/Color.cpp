#include "Color.hpp"

std::vector<ColorPalette> ColorPalette::palettes = {
    ColorPalette(
        "Classic",
        {
            QuadrominoColor(27, 208, 216),   // LIGHT_BLUE
            QuadrominoColor(206, 208, 29),   // YELLOW
            QuadrominoColor(208, 29, 150), // PINK
            QuadrominoColor(58, 45, 144),     // NAVY_BLUE
            QuadrominoColor(223, 121, 16),   // ORANGE
            QuadrominoColor(27, 215, 33),     // GREEN
            QuadrominoColor(201, 38, 255),     // RED
            QuadrominoColor(128, 128, 128), // GRAY
            QuadrominoColor(172, 172, 172, 128) // GHOST (semi-transparent)
        }
    )
};

ColorPalette &ColorPalette::currentPalette = ColorPalette::palettes.at(0);