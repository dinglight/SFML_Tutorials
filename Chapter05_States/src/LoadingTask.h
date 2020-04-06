#ifndef _LOADING_TASK_H_
#define _LOADING_TASK_H_

#include <thread>
#include <chrono>

class LoadingTask
{
public:
    LoadingTask();
    void Execute();
    bool IsFinished();
    float GetCompletion();
private:
    void RunTask();
private:
    std::thread mThread;
    std::chrono::system_clock::time_point mStartTimePoint;
    std::chrono::seconds mDuration;
};
#endif // _LOADING_TASK_H_