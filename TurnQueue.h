#ifndef COMPAREENTITY_H
#define COMPAREENTITY_H

#include "Entity.h"
#include "Skill.h"
#include <vector>
#include <queue>

class CompareSkill
{
    public:
    protected:
    private:
};

typedef std::priority_queue<Skill, std::vector<Skill>, CompareSkill> TurnQueue;

#endif // COMPAREENTITY_H
