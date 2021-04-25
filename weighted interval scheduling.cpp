#include <iostream>
#include <algorithm>
using namespace std;

int M[20];

struct Job {
    int s,f,w;
};

int p(Job jobs[], int j)
{

  for(int i = j - 1; i >= 0; i--)
  {
    if (jobs[i].f <= jobs[j].s)
    {
      return i;
    }
  }
  return 0;
}

bool compareJob(Job j1, Job j2)
{
  return (j1.f < j2.f);
}

int ComputeOpt(Job jobs[], int j)
{
  if (M[j] == -1)
  {
    M[j] = max(jobs[j].w + ComputeOpt(jobs, p(jobs, j)),
      ComputeOpt(jobs, j - 1));
    return M[j];
  }
}

void FindSolution(Job jobs[], int j)
{
  if (j == 0)
  {
    cout << "";
  }
  else if ((jobs[j].w + M[p(jobs, j)]) > M[j - 1])
  {
    cout << j << " ";
    FindSolution(jobs, p(jobs, j));
  }
  else
  {
    FindSolution(jobs, j - 1);
  }
}

void weightedIntervalScheduling(Job jobs[], int n)
{

  for(int i = 0; i < n; i++)
  {
    cout << endl << p(jobs, i) << " ";
  }
  cout << endl;

  sort(jobs, jobs + n, compareJob);

  M[0] = 0;
  for (int i = 1; i < n; i++)
    {

        int index = p(jobs, i);

        int incl = jobs[i].w;
        if (index != -1)
        {
            incl += M[index];
        }

        M[i] = max(incl, M[i-1]);
    }

  cout << M[n-1] << " is the optimal value.";
  cout << "\nOptimal Solution: ";
  FindSolution(jobs, n);
}
int main()
{
  int n;
  cout << "\nEnter the no of jobs: ";
  cin >> n;
  cout << "Enter the job details:\n";

  Job jobs[n];
  for(int i = 0; i < n; i++)
  {
    cout << "Starting time of Job " << i+1 << ": ";
    cin >> jobs[i].s;
    cout << "Finishing time of Job " << i+1 << ": ";
    cin >> jobs[i].f;
    cout << "Weight of Job " << i+1 << ": ";
    cin >> jobs[i].w;
    cout << endl;
  }

  weightedIntervalScheduling(jobs, n);

  return 0;
}
