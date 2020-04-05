#ifndef _PARALLEL_TASK_H_
#define _PARALLEL_TASK_H_
#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Clock.hpp>


class ParallelTask
{
public:
    ParallelTask();
    void Execute();
    bool IsFinished();
    float GetCompletion();
private:
    void RunTask();
private:
    sf::Thread mThread;
    sf::Mutex mMutex;
    sf::Clock mElapsedTime;
};
#endif // _PARALLEL_TASK_H_