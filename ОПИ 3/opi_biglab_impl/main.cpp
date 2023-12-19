#include <iostream>
#include <argh.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <array>
#include <random>
#include <chrono>
#include <list>

void save_file(std::string time, std::string summ, std::string nums_array) {
    std::ofstream file("results.bin");
    if (file.is_open()) {
        file << time << std::endl;
        file << summ << std::endl;
        file << nums_array << std::endl;
        file.close();
    }
}

int main(int, char* argv[])
{
    try {
        argh::parser cmdl(argv);

        std::string data_type = cmdl[1];
        std::string array_type = cmdl[2];
        std::string op_type = cmdl[3];

        std::string array_size = cmdl[4];
        std::string min_rand_range = cmdl[5];
        std::string max_rand_range = cmdl[6];
        int min_rand_range_int = atoi(min_rand_range.c_str());
        int max_rand_range_int = atoi(max_rand_range.c_str());
        int array_size_int = atoi(array_size.c_str());

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min_rand_range_int, max_rand_range_int);

        if (array_type == "Array") {
            if (data_type == "Int") {
                if (op_type == "Minus") {
                    
                    
                }
                else if (op_type == "Plus") {

                }
                else if (op_type == "Mult") {

                }
                else if (op_type == "Div") {

                }
                else if (op_type == "Sin") {

                }
                else if (op_type == "Cos") {

                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Float") {
                if (op_type == "Minus") {

                }
                else if (op_type == "Plus") {

                }
                else if (op_type == "Mult") {

                }
                else if (op_type == "Div") {

                }
                else if (op_type == "Sin") {

                }
                else if (op_type == "Cos") {

                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Double") {
                if (op_type == "Minus") {

                }
                else if (op_type == "Plus") {

                }
                else if (op_type == "Mult") {

                }
                else if (op_type == "Div") {

                }
                else if (op_type == "Sin") {

                }
                else if (op_type == "Cos") {

                }
                else {
                    return 2;
                }
            }
            else {
                return 2;
            }
        }
        else if (array_type == "Dyn array") {
            if (data_type == "Int") {
                if (op_type == "Minus") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] - vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] + vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] == 0) {
                            sum += vec[i] * 1;
                        }
                        else {
                            sum += vec[i] * vec[i - 1];
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] == 0) {
                            sum += vec[i] / 1;
                        }
                        else {
                            sum += vec[i] / vec[i - 1];
                        }

                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += sin(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::vector<int> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = int(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += cos(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Float") {
                if (op_type == "Minus") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] - vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] + vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] != 0) {
                            sum += vec[i] * vec[i - 1];
                        }
                        else {
                            sum += vec[i] * 1.0f;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] != 0) {
                            sum += vec[i] / vec[i - 1];
                        }
                        else {
                            sum += vec[i] / 1.0f;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += sin(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::vector<float> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = float(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += cos(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Double") {
                if (op_type == "Minus") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] - vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += vec[i] + vec[i - 1];
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] != 0) {
                            sum += vec[i] * vec[i - 1];
                        }
                        else {
                            sum += vec[i] * 1.0f;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        if (vec[i - 1] != 0) {
                            sum += vec[i] / vec[i - 1];
                        }
                        else {
                            sum += vec[i] / 1.0f;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += sin(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::vector<double> vec(array_size_int);
                    for (int i = 0; i < array_size_int; ++i) {
                        vec[i] = double(dis(rd));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += cos(vec[i]);
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
        }
        else if (array_type == "List") {
            if (data_type == "Int") {
                if (op_type == "Minus") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        sum -= x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        sum += x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        if (x == 0) {
                            sum *= 1;
                        }
                        else {
                            sum *= x;
                        }
                       
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        if (x == 0) {
                            sum /= 1;
                        }
                        else {
                            sum /= x;
                        }

                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        sum += sin(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::list<int> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(int(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int x : vec) {
                        sum += cos(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (int num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Float") {
                if (op_type == "Minus") {
                    std::list<float> vec;
                    for (float i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        sum -= x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::list<float> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        sum += x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::list<float> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        if (x == 0) {
                            sum *= 1;
                        }
                        else {
                            sum *= x;
                        }

                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::list<float> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        if (x == 0) {
                            sum /= 1;
                        }
                        else {
                            sum /= x;
                        }

                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::list<float> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        sum += sin(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::list<float> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(float(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (float x : vec) {
                        sum += cos(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (float num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Double") {
                if (op_type == "Minus") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        sum -= x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Plus") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        sum += x;
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Mult") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        if (x == 0) {
                            sum *= 1;
                        }
                        else {
                            sum *= x;
                        }

                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Div") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        if (x == 0) {
                            sum /= 1;
                        }
                        else {
                            sum /= x;
                        }

                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Sin") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        sum += sin(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else if (op_type == "Cos") {
                    std::list<double> vec;
                    for (int i = 0; i < array_size_int; ++i) {
                        vec.push_back(double(dis(rd)));
                    }
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (double x : vec) {
                        sum += cos(x);
                    }

                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    std::string formatted_array;
                    for (double num : vec) {
                        formatted_array += std::to_string(num) + ' ';
                    }

                    save_file(std::to_string(time), std::to_string(sum), formatted_array);
                }
                else {
                    return 2;
                }
            }
            else {
                return 2;
            }
        }
        else if (array_type == "For cycle") {
            if (data_type == "Int") {
                if (op_type == "Minus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += int(dis(rd)) - int(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Plus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += int(dis(rd)) + int(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Mult") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        int t = int(dis(rd));
                        if (t == 0) {
                            sum += int(dis(rd)) * 1;
                        }
                        else {
                            sum += int(dis(rd)) * t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Div") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        int t = int(dis(rd));
                        if (t == 0) {
                            sum += int(dis(rd)) / 1;
                        }
                        else {
                            sum += int(dis(rd)) / t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Sin") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += int(dis(rd)) + int(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Cos") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    int sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += int(cos(dis(rd)));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Float") {
                if (op_type == "Minus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += float(dis(rd)) - float(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Plus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += float(dis(rd)) + float(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Mult") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        float t = float(dis(rd));
                        if (t == 0) {
                            sum += float(dis(rd)) * 1;
                        }
                        else {
                            sum += float(dis(rd)) * t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Div") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        float t = float(dis(rd));
                        if (t == 0) {
                            sum += float(dis(rd)) / 1;
                        }
                        else {
                            sum += float(dis(rd)) / t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Sin") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += float(sin(dis(rd)));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Cos") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    float sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += float(cos(dis(rd)));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else {
                    return 2;
                }
            }
            else if (data_type == "Double") {
                if (op_type == "Minus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += double(dis(rd)) - double(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Plus") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        sum += double(dis(rd)) + double(dis(rd));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Mult") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        double t = double(dis(rd));
                        if (t == 0) {
                            sum += double(dis(rd)) * 1;
                        }
                        else {
                            sum += double(dis(rd)) * t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Div") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size - 1; ++i) {
                        double t = double(dis(rd));
                        if (t == 0) {
                            sum += double(dis(rd)) / 1;
                        }
                        else {
                            sum += double(dis(rd)) / t;
                        }
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Sin") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += double(sin(dis(rd)));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else if (op_type == "Cos") {
                    int size = array_size_int;

                    auto start = std::chrono::high_resolution_clock::now();

                    double sum = 0;
                    for (int i = 1; i < size; ++i) {
                        sum += double(cos(dis(rd)));
                    }


                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double, std::milli> duration = end - start;
                    double time = duration.count();

                    save_file(std::to_string(time), std::to_string(sum), "cant display for forcycle");
                }
                else {
                    return 2;
                }
            }
            else {
                return 2;
            }
        }
        else {
            return 2;
        }
    }
    catch (std::exception ex) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}