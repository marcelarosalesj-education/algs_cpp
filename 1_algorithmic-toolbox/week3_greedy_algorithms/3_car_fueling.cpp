#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int i = 0;
    int far = tank;
    int refills = 0;
    bool finish = false;
    while(!finish) {
        if (far >= dist) {
            finish = true;
        } else {
            if (i == stops.size()-1) {
                if (far >= stops[i]) {
                    if (stops[i]+tank < dist) {
                        finish = true;
                        refills = -1;
                    } else {
                        refills++;
                        finish = true;
                    }

                } else {
                    finish = true;
                    refills = -1;
                }

            }
            else if (stops[i] < far) { // go on
                if (stops[i+1]<=far) {
                    // go on one step
                    i++;
                } else {
                    // refill now at i
                    refills++;
                    far = stops[i] + tank;
                    i++;
                }
            } else if (stops[i] == far) {
                // refill now at i
                refills++;
                far = stops[i] + tank;
                i++;
            } else {
                refills = -1;
                finish = true;
            }
        }
    }

    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
