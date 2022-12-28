#pragma once

#include "Queue.h"

class TJobStream
{
protected:

  double jobInt�ns; // ������������� ������ �����
  size_t LastJobID;

public:

  TJobStream(double int�ns);
  size_t GetNewJob(void); // ��������� ������ �������
  double GetJobIntens(void) const noexcept;
  size_t GetLastTask(void) const noexcept;
};