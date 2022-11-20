#include "RandomGenerator.h"
#include "../Noise.h"
#include "../PerlinNoise.hpp"
#include <iostream>

std::vector<Color32> RandomScenarioGenerator::Generate(int sideSize, float displacement) 
{
  std::vector<Color32> colors;
  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);

  for(int l=0; l<sideSize; l++)
  {
    for(int c=0;c<sideSize; c++)
    {
      float nx = 2.0f * c / sideSize - 1;
      float ny = 2.0f * l / sideSize - 1;
      float d = 1 - (1 - nx * nx) * (1 - ny * ny);
      float rgb = abs(noise.octave3D(c/50.0,l/50.0, displacement, 2)*255);
      rgb += ((1 - d) * 255) - 120;
      if (rgb < 10)
      {
        colors.emplace_back(0, 0, 50);
      } 
      else if (rgb < 30)
      {
        colors.emplace_back(0, 0, 125);
      } 
      else if (rgb < 50)
      {
        colors.emplace_back(0, 0, 255);
      }  
      else if (rgb < 70) 
      {
        colors.emplace_back(194,178,128);
      } 
      else if (rgb < 100) 
      {
        colors.emplace_back(34, 139, 34);
      } 
      else if (rgb< 150) 
      {
        colors.emplace_back(50,205,0);
      } 
      else if (rgb< 200) 
      {
        colors.emplace_back(124, 252, 0);
      }
      else
          colors.emplace_back(255, 255, 255);
    }
  }
  std::cout<<colors.size() << std::endl;
  return colors;
}
std::string RandomScenarioGenerator::GetName() { return "Square Bump"; }
