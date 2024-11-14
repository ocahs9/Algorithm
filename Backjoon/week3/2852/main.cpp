#include <iostream>
#include <string>
using namespace std;

int getTimeFromString(string timeString)
{
  const int minute = stoi((timeString.substr(0, 2)));
  const int second = stoi((timeString.substr(3, 2)));

  int ret = (minute * 60) + second;
  return ret;
}

string getTimeFromInt(int time)
{
  int minute = time / 60;
  int second = time % 60;

  string minuteString = to_string(minute);
  string secondString = to_string(second);
  if (minuteString.size() == 1)
    minuteString = "0" + minuteString;
  if (secondString.size() == 1)
    secondString = "0" + secondString;

  return minuteString + ":" + secondString;
}

int n;
int main()
{

  cin >> n;
  string std = "48:00";
  int stdInt = getTimeFromString(std);
  int winningTime[2] = {0, 0};
  int score[2] = {0, 0};
  int forkTime = 0;
  int prevForkTime = 0;
  int winningTeam = -1;
  int team;
  string goalTime;
  for (int i = 0; i < n; i++)
  {
    cin >> team >> goalTime;
    // 딱 하나만 들어올 때도 고려해야함 (골이 딱 하나)
    if (i == 0)
    {
      score[team - 1] += 1;
      winningTeam = team;
      prevForkTime = getTimeFromString(goalTime);
    }
    else
    {
      int goalTimeInt = getTimeFromString(goalTime);
      score[team - 1] += 1;
      if (winningTeam != -1)
      {                                                             // 무승부 상태가
        winningTime[winningTeam - 1] += goalTimeInt - prevForkTime; // 현재 골 시간 - 이전 분기 시간
      }
      prevForkTime = goalTimeInt; // 분기 시간 갱신

      // 누가 이기는 중인지 확인
      if (score[0] == score[1])
        winningTeam = -1;
      else if (score[0] > score[1])
        winningTeam = 1;
      else
        winningTeam = 2;
    }
  }

  if (winningTeam != -1)
  {
    winningTime[winningTeam - 1] += stdInt - getTimeFromString(goalTime);
  }

  cout << getTimeFromInt(winningTime[0]) << endl;
  cout << getTimeFromInt(winningTime[1]) << endl;

  return 0;
}