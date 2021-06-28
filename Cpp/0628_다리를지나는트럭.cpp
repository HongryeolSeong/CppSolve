#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int bridge_length = 5;
    int weight = 5;
    vector<int> truck_weights = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };
    vector<int> on;
    vector<int> out;
    vector<int> time;
    int sz = truck_weights.size();
    int sum = 0;
    int cnt = 1;

    while (1)
    {
        if (time.size() > 0 && time[0] == bridge_length)
        {
            out.push_back(on[0]);
            on.erase(on.begin());
            time.erase(time.begin());
        }

        sum = 0;
        for (int i = 0; i < on.size(); i++)
        {
            sum += on[i];
        }

        if (truck_weights.size() > 0)
        {
            sum += truck_weights[0];
        }

        if (sum <= weight && on.size() < bridge_length)
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
            for (int i = 0; i < time.size(); i++)
            {
                time[i]++;
            }
        }

        if (out.size() == sz) break;

        cnt++;
    }

    cout << cnt;

    return 0;
}