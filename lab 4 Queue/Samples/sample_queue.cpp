#include <iostream>
#include "Proc.h"
#include <cstdlib>

int main()
{
  std::srand(std::time(nullptr));
  const size_t tests = 3;
  TProc proc[tests] = { TProc(0.5), TProc(0.2), TProc(0.5) };
  TJobStream stream[tests] = { TJobStream(0.5), TJobStream(0.5), TJobStream(0.2) };
  size_t tacts[tests] = { 10, 10, 10 };
  TVectorQueue<size_t> jobsqueue;

  for (size_t i = 0; i < tests; i++)
  {
	std::cout << tacts[i] << " tacts, queue size is 3, JobsIntense is " << \
	  stream[i].GetJobIntens() << ", proc rate is " << proc[i].GetProcRate() << '.' << std::endl;
	for (size_t j = 0; j < tacts[i]; j++)
	{
	  size_t temp_job = stream[i].GetNewJob();
	  if (temp_job > 0)
		jobsqueue.Push(temp_job);
	  if (!jobsqueue.isEmpty())
		if (proc[i].RunNewJob(jobsqueue.Top()))
		  jobsqueue.Pop();
	  proc[i].DoJob();
	}
	std::cout << "Jobs Generated " << stream[i].GetLastTask() << ", Proc Jobs Done " << \
	  proc[i].GetCompletedTasks() << ", Proc Jobs Overflow " << proc[i].GetTimeOverflow() << \
	  ", Proc No Jobs Tacts " << proc[i].GetIdle() << ", average " << ((double)(tacts[i]) / (double)(proc[i].GetCompletedTasks())) << \
	  " tacts done per job." << std::endl << std::endl;
  }
  return 0;
}