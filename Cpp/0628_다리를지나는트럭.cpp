#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };
    vector<int> on;
    vector<int> out;
    vector<int> time;
    int idx = 0;
    int sum = 0;
    int cnt = 1;

    while (1)
    {
        if (truck_weights.size() > 0)
        {
            sum += truck_weights[idx];
        }

        if (sum <= weight)
        {
            if (truck_weights.size() > 0)
            {
                on.push_back(truck_weights[0]);
                truck_weights.erase(truck_weights.begin());
            }

            time.push_back(0);
            for (int i = 0; i < time.size(); i++)
            {
                time[i]++;
            }
        }
        else
        {
            sum = 0;
            for (int i = 0; i < time.size(); i++)
            {
                time[i]++;
            }
        }

        if (time[0] == bridge_length + 1)
        {
            out.push_back(on[0]);
            on.erase(on.begin());
            time.erase(time.begin());
        }

        if (on.size() == 0) break;

        cnt++;
    }

    cout << cnt;

    return 0;
}