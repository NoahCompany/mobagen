#include "Catcher.h"
#include "World.h"

Point2D Catcher::Move(World* world) 
{
  neighbor.clear();
  searched.clear();
  path.clear();
  bool pathFound = false;
  int lowestWeight = 500;
  int choice = 0;
  queueEntry current;
  queueEntry next;
  queueEntry endPoint;
  auto pos = world->getCat();
  current.position = pos;
  current.totalWeight = 0;
  queueEntry start = current;
  do {
    lowestWeight = 500;
    if (neighbor.size() > 0) {
      for (int i = 0; i < neighbor.size(); i++) {
        if (neighbor[i].totalWeight < lowestWeight) {
          lowestWeight = neighbor[i].totalWeight;
          choice = i;
        }
      }
      current = neighbor[choice];
      neighbor.erase(neighbor.begin() + choice);
    }

    searched.push_back(current);
    if (abs(current.position.x) != world->getWorldSideSize() / 2 &&
        abs(current.position.y) != world->getWorldSideSize() / 2) {
      next.previous = current.position;
      if (!world->getContent(World::NE(current.position))) {
        next.position = World::NE(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      if (!world->getContent(World::NW(current.position))) {
        next.position = World::NW(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      if (!world->getContent(World::E(current.position))) {
        next.position = World::E(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      if (!world->getContent(World::W(current.position))) {
        next.position = World::W(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      if (!world->getContent(World::SE(current.position))) {
        next.position = World::SE(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      if (!world->getContent(World::SW(current.position))) {
        next.position = World::SW(current.position);
        next.totalWeight = current.totalWeight + 1;
        neighbor.push_back(next);
      }
      
    } else {
      endPoint = current;
      neighbor.clear();
    }
    for (int i = 0; i < searched.size(); i++) {
      for (int j = 0; j < neighbor.size(); j++) {
        if (searched[i].position == neighbor[j].position) {
          neighbor.erase(neighbor.begin() + j);
        }
      }
    }
    if (neighbor.size() == 0) pathFound = true;
  } while (!pathFound);
  Point2D p = Point2D(0, 0);
  auto side = world->getWorldSideSize() / 2;
  for (;;) {
    if (((abs(endPoint.position.x) == side ||
           abs(endPoint.position.y) == side)) && endPoint.position != pos && !world->getContent(endPoint.position)) 
    {
      p = endPoint.position;
      return p;
    }
    else 
    {
      p = {Random::Range(-side, side), Random::Range(-side, side)};
      if (pos.x != p.x && pos.y != p.y && !world->getContent(p)) 
      {
        return p;
      }
    }
  }
}