#ifndef AGENT_H
#define AGENT_H
#include "Point2D.h"
#include <unordered_map>
using namespace std;

class World;

struct queueEntry
{
  Point2D position = Point2D(0,0);
  int totalWeight;
  Point2D previous = Point2D(0,0);
};

class Agent 
{
public:
  explicit Agent()= default;;
  virtual Point2D Move(World*)=0;
  vector<queueEntry> searched;
  vector<queueEntry> neighbor;
  vector<queueEntry> path;
};

#endif  // AGENT_H
