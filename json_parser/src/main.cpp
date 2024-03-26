#include <iostream>
#include <fstream>
#include <memory>
#include "../include/nlohmann/json.hpp"

using json = nlohmann::json;







int main(){
    // create json object
    json j; // 首先创建一个空的json对象
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42; // 初始化answer对象
    j["list"] = { 1, 0, 2 }; // 使用列表初始化的方法对"list"数组初始化
    j["object"] = { {"currency", "USD"}, {"value", 42.99} }; // 初始化object对象



    // 读取json对象
    float pi = j.at("pi");
    std::string name = j.at("name");
    int everything = j.at("answer").at("everything");
    std::cout << pi << std::endl; // 输出: 3.141
    std::cout << name << std::endl; // 输出: Niels
    std::cout << everything << std::endl; // 输出: 42
    // 打印"list"数组
    for(int i=0; i<3; i++)
    std::cout << j.at("list").at(i) << std::endl;
    // 打印"object"对象中的元素
    std::cout << j.at("object").at("currency") << std::endl; // 输出: USD
    std::cout << j.at("object").at("value") << std::endl; // 输出: 42.99


    // write to json file
    std::ofstream file("pretty.json");
    file << j << std::endl;

    // read json file
    json j2;
    std::ifstream jfile("pretty.json");
	jfile >> j2;		// 以文件流形式读取 json 文件
    std::cout << "read json file" << std::endl;
    float pi2 = j2.at("pi");
    std::string name2 = j2.at("name");
    int everything2 = j2.at("answer").at("everything");
    std::cout << pi2 << std::endl; // 输出: 3.141
    std::cout << name2 << std::endl; // 输出: Niels
    std::cout << everything2 << std::endl; // 输出: 42  






    return 0;
}


