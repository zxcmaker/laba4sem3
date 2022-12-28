#include "JobStream.h"

TJobStream::TJobStream(double int�ns)
{
  if (int�ns < 0.0 || int�ns > 1.0) throw "intens > 1 or intens < 0";
  jobInt�ns = int�ns;
  LastJobID = 1;
}

size_t TJobStream::GetNewJob(void)
{
  double num;
  num = (double)rand() / (double)RAND_MAX;
  if (num <= jobInt�ns)
  {
    LastJobID++;
    return LastJobID - 1;
  }
  else return 0;
}

double TJobStream::GetJobIntens(void) const noexcept
{
  return jobInt�ns;
}

size_t TJobStream::GetLastTask(void) const noexcept
{
  return LastJobID;
}
