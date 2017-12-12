/*
   Tree v2: https://github.com/evilgeniuslabs/tree-v2
   Copyright (C) 2016 Jason Coon

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

const uint8_t radii[NUM_LEDS] = {
    76, 161, 255, 255, 161, 76, 76, 161, 255, 255, 161, 76, 76, 161, 255, 255, 161, 76, 76, 161, 255, 255, 161, 76, 76, 161, 255, 255, 161, 76, 76, 161, 255, 255, 161, 76, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 66, 151, 246, 246, 151, 66, 57, 142, 227, 227, 142, 57, 57, 142, 227, 227, 142, 57, 57, 142, 227, 227, 142, 57, 57, 142, 227, 227, 142, 57, 57, 142, 227, 227, 142, 57, 57, 142, 227, 227, 142, 57, 57, 113, 170, 170, 113, 57, 57, 113, 170, 170, 113, 57, 57, 113, 170, 170, 113, 57, 57, 113, 170, 170, 113, 57, 57, 113, 170, 170, 113, 57, 57, 113, 170, 170, 113, 57, 47, 123, 123, 47, 47, 123, 123, 47, 47, 123, 123, 47, 47, 123, 123, 47, 47, 123, 123, 47, 47, 123, 123, 47, 113, 113, 113, 113, 113, 113, 113, 113, 94, 94, 94, 94, 94, 94, 94, 76, 76, 76, 76, 76, 76, 76, 57, 57, 57, 57, 57, 57, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 0, 0, 0, 0
};

const uint8_t conicalRadii[NUM_LEDS] = {
  0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};

const uint8_t angles[NUM_LEDS] = {
  0, 0, 0, 0, 0, 0, 43, 43, 43, 43, 43, 43, 85, 85, 85, 85, 85, 85, 128, 128, 128, 128, 128, 128, 171, 171, 171, 171, 171, 171, 213, 213, 213, 213, 213, 213, 235, 235, 235, 235, 235, 235, 21, 21, 21, 21, 21, 21, 64, 64, 64, 64, 64, 64, 107, 107, 107, 107, 107, 107, 149, 149, 149, 149, 149, 149, 192, 192, 192, 192, 192, 192, 235, 235, 235, 235, 235, 235, 0, 0, 0, 0, 0, 0, 43, 43, 43, 43, 43, 43, 85, 85, 85, 85, 85, 85, 128, 128, 128, 128, 128, 128, 171, 171, 171, 171, 171, 171, 192, 192, 192, 192, 192, 192, 235, 235, 235, 235, 235, 235, 21, 21, 21, 21, 21, 21, 64, 64, 64, 64, 64, 64, 107, 107, 107, 107, 107, 107, 149, 149, 149, 149, 149, 149, 171, 171, 171, 171, 171, 171, 213, 213, 213, 213, 213, 213, 0, 0, 0, 0, 0, 0, 43, 43, 43, 43, 43, 43, 85, 85, 85, 85, 85, 85, 128, 128, 128, 128, 128, 128, 149, 149, 149, 149, 192, 192, 192, 192, 235, 235, 235, 235, 21, 21, 21, 21, 64, 64, 64, 64, 107, 107, 107, 107, 160, 192, 224, 0, 32, 64, 96, 128, 128, 165, 201, 238, 18, 55, 91, 128, 165, 201, 238, 18, 55, 91, 128, 171, 213, 0, 43, 85, 128, 192, 0, 64, 96, 160, 224, 32, 43, 128, 213, 0, 85, 171, 192, 192, 64, 64
};

const uint8_t levelCount = 16;
const uint8_t ledsPerLevel[levelCount] = { 36, 36, 36, 36, 36, 24, 8, 7, 7, 6, 4, 4, 3, 3, 2, 2};

const uint16_t levelStart[levelCount] = {
  0,
  36,
  72,
  108,
  144,
  180,
  204,
  212,
  219,
  226,
  232,
  236,
  240,
  243,
  246,
  248
};

const uint16_t levelEnd[levelCount] = {
  35,
  71,
  107,
  143,
  179,
  203,
  211,
  218,
  225,
  231,
  235,
  239,
  242,
  245,
  247,
  249
};

const uint8_t levels[NUM_LEDS] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
  6, 6, 6, 6, 6, 6, 6, 6,
  7, 7, 7, 7, 7, 7, 7,
  8, 8, 8, 8, 8, 8, 8,
  9, 9, 9, 9, 9, 9,
  10, 10, 10, 10,
  11, 11, 11, 11,
  12, 12, 12,
  13, 13, 13,
  14, 15,
  15, 14
};

const uint8_t zCoords[NUM_LEDS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
    52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,
    82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138,
    156, 156, 156, 156, 156, 156, 156, 156,
    169, 169, 169, 169, 169, 169, 169,
    182, 182, 182, 182, 182, 182, 182,
    190, 190, 190, 190, 190, 190,
    199, 199, 199, 199,
    207, 207, 207, 207,
    216, 216, 216,
    229, 229, 229,
    242, 255,
    255, 242
};

const uint8_t xCoords[NUM_LEDS] = {
  128, 128, 128, 128, 128, 128, 164, 201, 243, 243, 201, 164, 164, 201, 243, 243, 201, 164, 128, 128, 128, 128, 128, 128, 91, 54, 12, 12, 54, 91, 91, 54, 12, 12, 54, 91, 109, 88, 65, 65, 88, 109, 146, 167, 190, 190, 167, 146, 165, 208, 255, 255, 208, 165, 146, 167, 190, 190, 167, 146, 109, 88, 65, 65, 88, 109, 90, 47, 0, 0, 47, 90, 109, 88, 65, 65, 88, 109, 128, 128, 128, 128, 128, 128, 160, 197, 238, 238, 197, 160, 160, 197, 238, 238, 197, 160, 128, 128, 128, 128, 128, 128, 95, 58, 17, 17, 58, 95, 94, 52, 9, 9, 52, 94, 111, 90, 69, 69, 90, 111, 144, 165, 186, 186, 165, 144, 161, 203, 246, 246, 203, 161, 144, 165, 186, 186, 165, 144, 111, 90, 69, 69, 90, 111, 99, 74, 49, 49, 74, 99, 99, 74, 49, 49, 74, 99, 128, 128, 128, 128, 128, 128, 156, 181, 206, 206, 181, 156, 156, 181, 206, 206, 181, 156, 128, 128, 128, 128, 128, 128, 114, 95, 95, 114, 99, 61, 61, 99, 114, 95, 95, 114, 141, 160, 160, 141, 156, 194, 194, 156, 141, 160, 160, 141, 84, 66, 84, 128, 171, 189, 171, 128, 128, 87, 77, 105, 150, 178, 168, 128, 94, 86, 109, 146, 169, 161, 128, 99, 99, 128, 156, 156, 128, 99, 128, 156, 148, 107, 107, 148, 152, 128, 103, 128, 152, 103, 123, 123, 132, 132
};

const uint8_t yCoords[NUM_LEDS] = {
  168, 209, 255, 255, 209, 168, 148, 168, 190, 190, 168, 148, 107, 87, 65, 65, 87, 107, 87, 46, 0, 0, 46, 87, 107, 87, 65, 65, 87, 107, 148, 168, 190, 190, 168, 148, 159, 195, 234, 234, 195, 159, 159, 195, 234, 234, 195, 159, 128, 128, 128, 128, 128, 128, 96, 60, 21, 21, 60, 96, 96, 60, 21, 21, 60, 96, 128, 128, 128, 128, 128, 128, 159, 195, 234, 234, 195, 159, 164, 205, 250, 250, 205, 164, 145, 166, 188, 188, 166, 145, 110, 89, 67, 67, 89, 110, 91, 50, 5, 5, 50, 91, 110, 89, 67, 67, 89, 110, 128, 128, 128, 128, 128, 128, 155, 191, 227, 227, 191, 155, 155, 191, 227, 227, 191, 155, 128, 128, 128, 128, 128, 128, 100, 64, 28, 28, 64, 100, 100, 64, 28, 28, 64, 100, 112, 98, 85, 85, 98, 112, 143, 157, 170, 170, 157, 143, 159, 187, 214, 214, 187, 159, 143, 157, 170, 170, 157, 143, 112, 98, 85, 85, 98, 112, 96, 68, 41, 41, 68, 96, 104, 72, 72, 104, 128, 128, 128, 128, 151, 183, 183, 151, 151, 183, 183, 151, 128, 128, 128, 128, 104, 72, 72, 104, 86, 128, 169, 187, 169, 128, 86, 68, 77, 97, 138, 173, 173, 138, 97, 87, 102, 136, 165, 165, 136, 102, 96, 112, 143, 159, 143, 112, 100, 128, 155, 128, 108, 108, 147, 147, 141, 100, 141, 155, 114, 114, 128, 128, 128, 128
};

uint16_t getNearestToAngleAndLevel(uint8_t angle, uint8_t level) {
  uint8_t smallestDifference = 255;
  uint8_t nearestIndex = 0;

  for(uint16_t i = 0; i < NUM_LEDS; i++) {
    if(levels[i] != level)
      continue;

    uint8_t currentAngle = angles[i];

    uint8_t difference = abs(currentAngle - angle);

    if(difference > smallestDifference)
      continue;
    else if (difference == smallestDifference && random8() > 127)
      continue;

    smallestDifference = difference;
    nearestIndex = i;
  }

  return nearestIndex;
}
