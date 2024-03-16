#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int code(std::vector<std::vector<int>>& random_matrix) {
    int n = random_matrix.size();
    int a = -1000000, c = 1000000, b = n - 1;
    int countn = 0;

    for (int i = 0; i < n; i++) {
        int r = random_matrix[i][b];
        if (r != 0)
        {
            b -= 1;
            countn += 4;
            if (r < 0 && r > a) a = r, countn += 3;
            else if (r > 0 && r < c) c = r, countn += 5;
        }
        countn += 4;
    }

    return countn;
}

std::vector<std::vector<int>> generate_random_matrix(int n) {
    std::vector<std::vector<int>> matrix;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10000, 10000);

    for (int i = 0; i < n; i++) {
        std::vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(dis(gen));
        }
        matrix.push_back(row);
    }
    return matrix;
}

std::vector<std::vector<int>> generate_best_matrix(int n) {
    std::vector<std::vector<int>> best_matrix;

    for (int i = 0; i < n; i++) {
        std::vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
        }
        best_matrix.push_back(row);
    }
    return best_matrix;
}

std::vector<std::vector<int>> generate_worst_matrix(int n) {
    std::vector<std::vector<int>> worst_matrix;
    int a = n;
    for (int i = 0; i < n; i++) {
        std::vector<int> row;
        
        for (int j = 0; j < n; j++) {
            row.push_back(a);
        }
        worst_matrix.push_back(row);
        a--;
    }

    return worst_matrix;
}



int main() {
    int n = 100, countn;
    unsigned int end_time;
    std::ofstream myfile;
    myfile.open("alg2.csv");
    myfile << "X;timeRand;operRand;X;timeBest;operBest;X;timeWorst;operWorst\n";
    unsigned int start_time = clock();
    for (int i = 0; i < 10; ++i)
    {       
        std::vector<std::vector<int>> random_matrix = generate_random_matrix(n);
        countn = code(random_matrix);
        end_time = clock();
        myfile << n*n << ';' << (end_time - start_time) << ";" << countn << ";";

        std::vector<std::vector<int>> best_matrix = generate_best_matrix(n);
        countn = code(best_matrix);
        myfile << n*n << ';' << (end_time - start_time) << ";" << countn << ";";

        
        std::vector<std::vector<int>> worst_matrix = generate_worst_matrix(n);
        countn = code(worst_matrix);
        myfile << n*n << ';' <<(end_time - start_time) << ";" << countn << "\n";
        n += 100;
    }

    myfile.close();
    return 0;
}
