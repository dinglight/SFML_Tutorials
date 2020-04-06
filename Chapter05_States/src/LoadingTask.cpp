#include "LoadingTask.h"
#include "Logger.h"

LoadingTask::LoadingTask()
: mThread(&LoadingTask::RunTask, this)
, mDuration(10)
{

}
void LoadingTask::Execute()
{
    LOG(INFO) << std::chrono::duration_cast<std::chrono::microseconds>(mDuration).count();
    mStartTimePoint = std::chrono::system_clock::now();
    mThread.join();
}
bool LoadingTask::IsFinished()
{
    auto currentTimePoint = std::chrono::system_clock::now();
    auto duration = currentTimePoint - mStartTimePoint;
    return (duration >= mDuration);
}
float LoadingTask::GetCompletion()
{
    auto currentTimePoint = std::chrono::system_clock::now();
    auto duration = currentTimePoint - mStartTimePoint;
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    auto total = std::chrono::duration_cast<std::chrono::microseconds>(mDuration).count();
    return (ms * 1.f / total);
}

void LoadingTask::RunTask()
{
    auto currentTimePoint = std::chrono::system_clock::now();
    auto duration = currentTimePoint - mStartTimePoint;

    while (duration < mDuration) {
        currentTimePoint = std::chrono::system_clock::now();
        duration = currentTimePoint - mStartTimePoint;
    }
}