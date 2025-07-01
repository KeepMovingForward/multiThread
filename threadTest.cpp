#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

void partialSum(const std::vector<int>& data, int start, int end, long long& result) {
    result = std::accumulate(data.begin() + start, data.begin() + end, 0LL);
}

int main() {
    std::vector<int> data(1'000'000, 1);
    long long sum1 = 0, sum2 = 0;

    std::thread t1(partialSum, std::ref(data), 0, 500000, std::ref(sum1));
    std::thread t2(partialSum, std::ref(data), 500000, 1000000, std::ref(sum2));

    t1.join();
    t2.join();

    std::cout << "Total Sum = " << (sum1 + sum2) << '\n';
    return 0;
}
