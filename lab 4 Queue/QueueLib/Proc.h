#pragma once
#include "JobStream.h"

class TProc
{
protected:

  double procRate;				// ������������������ ����������
								 //int jobId; // Id ������������ �������
  size_t timeOverflow;
  size_t idle;
  size_t completedTasks;
  TVectorQueue<size_t> Jobs;

public:

  TProc(double rate);
  size_t IsProcBusy(void);				// ����� �� ���������?
  bool IsProcFull(void) const noexcept;
  size_t RunNewJob(size_t _jobId);     // ���������� � ���������� ���������� �������
  double GetProcRate(void) const noexcept;
  size_t DoJob(void);
  size_t GetTimeOverflow(void) const noexcept;
  size_t GetIdle(void) const noexcept;
  size_t GetCompletedTasks(void) const noexcept;
};