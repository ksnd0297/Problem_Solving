#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#define INF 987654321
using namespace std;


class Process {
public:
	int InTime;
	int EndTime;
	int Size;
	int PID;

	Process(int InTime, int EndTime, int Size, int PID) {
		this->InTime = InTime;
		this->EndTime = EndTime;
		this->Size = Size;
		this->PID = PID;
	}
};

class Area {
public:
	int Start;
	int End;
	int EndTime;
	int PID;
	Area(int Start, int End, int EndTime, int PID) {
		this->Start = Start;
		this->End = End;
		this->EndTime = EndTime;
		this->PID = PID;
	}
};

int N;
queue<Process> Queue;

int FirstFit() {
	int T = 0;
	queue<Process> process = Queue;
	queue<Process> waitQueue;
	vector<Area> area;

	area.push_back(Area(0, 0, 0, 0)); // 0의 공간 확보
	area.push_back(Area(1000, 987654321, 987654321, 987654321)); // 1000까지의 공간 확보

	while (!process.empty()) {
		Process nowProcess = process.front(); process.pop();
		int T = nowProcess.InTime;

		if (!waitQueue.empty()) {
			while (1) {
				int leastTime = 987654321; int index = 0;
				for (int i = 1; i < area.size() - 1; i++) {
					if (area[i].EndTime < leastTime) leastTime = area[i].EndTime;
				}

				if (leastTime > T) break; 

				for (int i = 1; i < area.size() - 1; i++)
					while (area[i].EndTime == leastTime)
						area.erase(area.begin() + i);

				int length = waitQueue.size();
				for (int i = 0; i < length; i++)
				{
					Process waitProcess = waitQueue.front(); waitQueue.pop();
					bool flag = false;
					for (int i = 0; !flag && i < area.size() - 1; i++) {
						if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
							area.insert(area.begin() + i + 1, Area(area[i].End, area[i].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));
							flag = true;
						}
					}
					if (!flag) waitQueue.push(waitProcess);
				}
			}
		}

		for (int i = 1; i < area.size() - 1; i++)
			while (T >= area[i].EndTime)
				area.erase(area.begin() + i);

		bool flag = false;
		for (int i = 0; !flag && i < area.size() - 1; i++) {
			if (area[i + 1].Start - area[i].End >= nowProcess.Size) {
				if (nowProcess.PID == N - 1) {
					return area[i].End;
				}
				area.insert(area.begin() + i + 1, Area(area[i].End, area[i].End + nowProcess.Size, T + nowProcess.EndTime, nowProcess.PID));
				flag = true;
			}
		}
		if (!flag) waitQueue.push(nowProcess);
	}

	while (1) {
		int leastTime = 987654321; int index = 0;
		for (int i = 1; i < area.size() - 1; i++) {
			if (area[i].EndTime < leastTime) leastTime = area[i].EndTime;
		}

		for (int i = 1; i < area.size() - 1; i++)
			while (area[i].EndTime == leastTime)
				area.erase(area.begin() + i);

		int length = waitQueue.size();
		for (int i = 0; i < length; i++)
		{
			Process waitProcess = waitQueue.front(); waitQueue.pop();
			bool flag = false;
			for (int i = 0; !flag && i < area.size() - 1; i++) {
				if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
					if (waitProcess.PID == N - 1) return area[i].End;
					area.insert(area.begin() + i + 1, Area(area[i].End, area[i].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));
					flag = true;
				}
			}
			if (!flag) waitQueue.push(waitProcess);
		}
	}
}

int BestFit() {
	int T = 0;
	queue<Process> process = Queue;
	queue<Process> waitQueue;
	vector<Area> area;

	area.push_back(Area(0, 0, 0, 0)); // 0의 공간 확보
	area.push_back(Area(1000, 987654321, 987654321, 987654321)); // 1000까지의 공간 확보

	while (!process.empty()) {
		Process nowProcess = process.front(); process.pop();
		int T = nowProcess.InTime;

		while (1) {
			int leastTime = 987654321; int index = -1;
			for (int i = 1; i < area.size() - 1; i++) {
				if (area[i].EndTime < leastTime) leastTime = area[i].EndTime;
			}

			if (leastTime > T) break;

			for (int i = 1; i < area.size() - 1; i++)
				while (area[i].EndTime == leastTime)
					area.erase(area.begin() + i);

			int length = waitQueue.size();
			for (int i = 0; i < length; i++)
			{
				Process waitProcess = waitQueue.front(); waitQueue.pop();
				bool flag = false;
				index = -1; int minSize = 987654321;
				for (int i = 0; i < area.size() - 1; i++) {
					if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
						if (minSize > area[i + 1].Start - area[i].End) {
							minSize = area[i + 1].Start - area[i].End;
							index = i;
						}
					}
				}
				if (minSize == INF) waitQueue.push(waitProcess);
				else {
					area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));

				}
			}
		}

		for (int i = 1; i < area.size() - 1; i++)
			while (area[i].EndTime <= T)
				area.erase(area.begin() + i);


		int length = area.size(); bool flag = false;
		int index = -1; int minSize = 987654321;
		for (int i = 0; i < length - 1; i++) {
			if (area[i + 1].Start - area[i].End >= nowProcess.Size) {
				if (minSize > area[i + 1].Start - area[i].End) {
					minSize = area[i + 1].Start - area[i].End;
					index = i;
				}
			}
		}
		if (minSize == INF) waitQueue.push(nowProcess);
		else {
			if (nowProcess.PID == N - 1) {
				return area[index].End;
			}
			area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + nowProcess.Size, T + nowProcess.EndTime, nowProcess.PID));
		}
	}

	while (1) {
		int leastTime = 987654321; int index = 0;
		for (int i = 1; i < area.size() - 1; i++) {
			if (area[i].EndTime < leastTime) leastTime = area[i].EndTime;
		}


		for (int i = 1; i < area.size() - 1; i++)
			while (area[i].EndTime == leastTime)
				area.erase(area.begin() + i);

		int length = waitQueue.size();
		for (int i = 0; i < length; i++)
		{
			Process waitProcess = waitQueue.front(); waitQueue.pop();
			int length = area.size();
			bool flag = false;
			int index = -1; int minSize = INF;
			for (int i = 0; i < length - 1; i++) {
				if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
					if (minSize > area[i + 1].Start - area[i].End) {
						minSize = area[i + 1].Start - area[i].End; index = i;
					}
				}
			}
			if (minSize == INF) waitQueue.push(waitProcess);
			else {
				if (waitProcess.PID == N - 1) return area[index].End;
				area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));
			}
		}
	}
}

int WorstFit() {
	int T = 0;
	queue<Process> process = Queue;
	queue<Process> waitQueue;
	vector<Area> area;

	area.push_back(Area(0, 0, 0, 0)); // 0의 공간 확보
	area.push_back(Area(1000, 987654321, 987654321, 987654321)); // 1000까지의 공간 확보

	while (!process.empty()) {
		Process nowProcess = process.front(); process.pop();
		int T = nowProcess.InTime;

		while (1) {
			int leastTime = 987654321; int index = -1;
			for (int i = 1; i < area.size() - 1; i++)
				if (area[i].EndTime < leastTime)
					leastTime = area[i].EndTime;

			if (leastTime > T) break;

			for (int i = 1; i < area.size() - 1; i++)
				while (area[i].EndTime == leastTime)
					area.erase(area.begin() + i);

			int length = waitQueue.size();
			for (int i = 0; i < length; i++)
			{
				Process waitProcess = waitQueue.front(); waitQueue.pop();
				int length = area.size(); bool flag = false;
				index = -1; int maxSize = 0;
				for (int i = 0; i < length - 1; i++) {
					if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
						if (maxSize < area[i + 1].Start - area[i].End) {
							maxSize = area[i + 1].Start - area[i].End;
							index = i;
						}
					}
				}
				if (maxSize == 0) waitQueue.push(waitProcess);
				else {
					area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));
				}
			}
		}

		for (int i = 1; i < area.size() - 1; i++)
			while (area[i].EndTime <= T)
				area.erase(area.begin() + i);


		int length = area.size(); bool flag = false;
		int index = -1; int maxSize = 0;
		for (int i = 0; i < length - 1; i++) {
			if (area[i + 1].Start - area[i].End >= nowProcess.Size) {
				if (maxSize < area[i + 1].Start - area[i].End) {
					maxSize = area[i + 1].Start - area[i].End;
					index = i;
				}
			}
		}
		if (maxSize == 0) waitQueue.push(nowProcess);
		else {
			if (nowProcess.PID == N - 1) return area[index].End;
			area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + nowProcess.Size, T + nowProcess.EndTime, nowProcess.PID));
		}
	}

	while (1) {
		int leastTime = 987654321; int index = 0;
		for (int i = 1; i < area.size() - 1; i++) {
			if (area[i].EndTime < leastTime) {
				leastTime = area[i].EndTime; index = i;
			}
		}

		for (int i = 1; i < area.size() - 1; i++)
			while (area[i].EndTime == leastTime)
				area.erase(area.begin() + i);


		int length = waitQueue.size();
		for (int i = 0; i < length; i++)
		{
			Process waitProcess = waitQueue.front(); waitQueue.pop();
			int length = area.size();
			bool flag = false;
			int index = -1; int maxSize = 0;
			for (int i = 0; i < length - 1; i++) {
				if (area[i + 1].Start - area[i].End >= waitProcess.Size) {
					if (maxSize < area[i + 1].Start - area[i].End) {
						maxSize = area[i + 1].Start - area[i].End; index = i;
					}
				}
			}
			if (maxSize == 0) waitQueue.push(waitProcess);
			else {
				if (waitProcess.PID == N - 1) return area[index].End;
				area.insert(area.begin() + index + 1, Area(area[index].End, area[index].End + waitProcess.Size, leastTime + waitProcess.EndTime, waitProcess.PID));
			}
		}
	}
}

int main(void) {

	freopen("allocation.inp", "r", stdin);
	freopen("allocation.out", "w", stdout);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int InTime, EndTime, Size;
		cin >> InTime >> EndTime >> Size;
		Queue.push(Process(InTime, EndTime, Size, i));
	}

	cout << FirstFit() << '\n';
	cout << BestFit() << '\n';
	cout << WorstFit() << '\n';

	return 0;
}