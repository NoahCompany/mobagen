#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <vector>
using namespace std;

Point2D Cat::Move(World* world) 
{
  neighbor.clear();
  queueEntry current;
  queueEntry next;
  auto choice = 0;
  auto pos = world->getCat();
  current.position = pos;
  if (searched.size() > 0)
    current.totalWeight = searched[searched.size()-1].totalWeight + 1;
  else 
  {
    current.totalWeight = 1;
  }
  searched.push_back(current);
  next.position = World::NE(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  next.position = World::NW(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  next.position = World::E(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  next.position = World::W(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  next.position = World::SE(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  next.position = World::SW(pos);
  next.totalWeight = current.totalWeight + 1;
  neighbor.push_back(next);
  return neighbor[neighbor.size()-3].position;
  switch(choice)
  {
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }
    
}
