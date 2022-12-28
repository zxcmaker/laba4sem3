#include "JobStream.h"

TJobStream::TJobStream(double intåns)
{
  if (intåns < 0.0 || intåns > 1.0) throw "intens > 1 or intens < 0";
  jobIntåns = intåns;
  LastJobID = 1;
}

size_t TJobStream::GetNewJob(void)
{
  double num;
  num = (double)rand() / (double)RAND_MAX;
  if (num <= jobIntåns)
  {
    LastJobID++;
    return LastJobID - 1;
  }
  else return 0;
}

double TJobStream::GetJobIntens(void) const noexcept
{
  return jobIntåns;
}

size_t TJobStream::GetLastTask(void) const noexcept
{
  return LastJobID;
}
