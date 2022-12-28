#include "Proc.h"

TProc::TProc(double rate)
{
  if (rate < 0.0 || rate > 1.0) throw "Error: rate < 0 or rate > 1";
  procRate = rate;
  idle = 0;
  timeOverflow = 0;
  completedTasks = 0;
}

size_t TProc::IsProcBusy(void)
{
  if (Jobs.isEmpty()) return 0;
  else return Jobs.Top();
}

bool TProc::IsProcFull(void) const noexcept
{
  return Jobs.isFull();
}

size_t TProc::RunNewJob(size_t _jobId)
{
  if (_jobId > 0)
  {
    if (IsProcFull())
    {
      timeOverflow++;
      return 0;
    }
    else
    {
      Jobs.Push(_jobId);
      return _jobId;
    }
  }
}

double TProc::GetProcRate(void) const noexcept
{
  return procRate;
}

size_t TProc::DoJob(void)
{
  if (!IsProcBusy())
  {
    idle++;
    return 0;
  }
  double num;
  num = (double)rand() / (double)RAND_MAX;
  if (num <= procRate && IsProcBusy())
  {
    size_t LastJob = Jobs.Pop();
    completedTasks++;
    return LastJob;
  }
  else return Jobs.Top();
}

size_t TProc::GetTimeOverflow(void) const noexcept
{
  return timeOverflow;
}

size_t TProc::GetIdle(void) const noexcept
{
  return idle;
}

size_t TProc::GetCompletedTasks(void) const noexcept
{
  return completedTasks;
}
