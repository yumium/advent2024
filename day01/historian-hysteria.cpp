#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

int total_distance(std::vector<int>& left, std::vector<int>& right) {
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    auto total = 0;
    const auto N = left.size();
    for (auto i = 0; i < N; i++) {
        total += std::abs(left[i] - right[i]);
    }

    return total;
}

int main() {
    std::string filePath = "./input.txt"; // Path to the file
    std::ifstream file(filePath);         // Open the file

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();               // Read the file content into the buffer
    std::string fileContent = buffer.str(); // Convert buffer content to string

    file.close(); // Close the file

    std::istringstream stream(fileContent); // Create a stream from the string

    std::string line;
    std::vector<int> left, right;
    while (std::getline(stream, line)) {
        left.push_back(std::stoi(line.substr(0, 5)));
        right.push_back(std::stoi(line.substr(8, 5)));
    }

    const auto ans = total_distance(left, right);
    std::cout << "Answer is: " << ans << std::endl;
}
