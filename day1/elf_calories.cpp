#include "elf_calories.hpp"

int main(){
    std::string line;
    std::ifstream pFile("input.txt"); //local input puzzle file
    uint64_t sum = 0;
    uint64_t maxSum = 0;
    uint64_t maxElf = 0;
    uint64_t elf = 0;
    if(pFile.is_open()){
        while(std::getline(pFile,line)){
            if(line.length()>0){
                sum+= stoi(line); // convert the string to an int
            }else{ // New line
                elf++;
                //std::cout<< "elf: " << elf << "\nhad sum: " << sum << std::endl;
                if(sum>maxSum){
                    maxSum = sum;
                    maxElf = elf;
                }
                sum = 0;
            }
        }
        elf++;
        if(sum>maxSum){
            maxSum = sum;
            maxElf = elf;
        }
    }
    pFile.close();
    std::cout << "Max calorie elf: " << maxElf << std::endl;
    std::cout << "Max calories: " << maxSum << std::endl;
    return 0;
}