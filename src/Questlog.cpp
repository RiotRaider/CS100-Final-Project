#ifndef __QUESTLOG_CPP__
#define __QUESTLOG_CPP__
#include "../header/Questlog.hpp"
#include <iostream>
QuestLog::QuestLog()
{
currQuest =0;
}
QuestLog::~QuestLog()
{
//delete everything
int size = quests.size();
for(unsigned i=0; i< size; i++)
	{
        delete quests.at(i);
        }
}


Quest* QuestLog::getCurrent()
{
return quests.at(currQuest);
}
void QuestLog::addQuest(Quest* input)
{
quests.push_back(input);
}
void QuestLog::updateQuest()
{
currQuest = currQuest+1;
}
std::string QuestLog::checkQuest()
{
return quests.at(currQuest)->getObj();
}
#endif //__QUESTLOG_CPP__
