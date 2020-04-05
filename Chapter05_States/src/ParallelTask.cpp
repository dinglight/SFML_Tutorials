#include "ParallelTask.h"
#include <SFML/System/Lock.hpp>

ParallelTask::ParallelTask()
: mThread(&ParallelTask::RunTask, this)
, mElapsedTime()
{

}
void ParallelTask::Execute()
{
    mElapsedTime.restart();
    mThread.launch();
}
bool ParallelTask::IsFinished()
{
    sf::Lock lock(mMutex);
    return (mElapsedTime.getElapsedTime().asSeconds() >= 10.f);
}
float ParallelTask::GetCompletion()
{
    sf::Lock lock(mMutex);
    return (mElapsedTime.getElapsedTime().asSeconds() / 10.f);
}

void ParallelTask::RunTask()
{
    while (mElapsedTime.getElapsedTime().asSeconds() < 10.f) {
        ;
    }
}