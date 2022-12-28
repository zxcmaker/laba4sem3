#pragma once
#include "JobStream.h"

class TProc
{
protected:

  double procRate;				// производительность процессора
								 //int jobId; // Id выполняемого задания
  size_t timeOverflow;
  size_t idle;
  size_t completedTasks;
  TVectorQueue<size_t> Jobs;

public:

  TProc(double rate);
  size_t IsProcBusy(void);				// занят ли процессор?
  bool IsProcFull(void) const noexcept;
  size_t RunNewJob(size_t _jobId);     // приступить к выполнению очередного задания
  double GetProcRate(void) const noexcept;
  size_t DoJob(void);
  size_t GetTimeOverflow(void) const noexcept;
  size_t GetIdle(void) const noexcept;
  size_t GetCompletedTasks(void) const noexcept;
};