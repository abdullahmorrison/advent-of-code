#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int getDigit(std::string line, int index){
  if(isdigit(line[index])) return line[index]-'0';

  std::vector<std::string> nums = {"zero","one","two","three","four","five","six","seven","eight","nine"};

  for(int i=0; i<nums.size(); i++){
    if(line.substr(index, nums[i].size())==nums[i]) return i;
  }

  return -1;
}

int getNum(std::string str){
  int l=0;
  int r=str.size()-1;

  int lNum = -1;
  int rNum = -1;
  while(l<=r && (lNum==-1 ||rNum==-1)){
    lNum = getDigit(str, l);
    rNum = getDigit(str, r);

    if(lNum==-1) l++;
    if(rNum==-1) r--;
  }
  // std::cout<< (lNum*10)+rNum<<"\n";
  return (lNum*10)+rNum;
}

int main(){
  std::ifstream file;
  file.open("input.txt");

  std::string line;
  if(file.is_open()){
    try{
      int sum = 0;
      while(std::getline(file, line)){
        sum += getNum(line);
      }
      std::cout << sum << "\n";
    }catch(std::exception& e){
      std::cout << "error: "<< e.what() << "\n";
    }
    file.close();
  } else std::cout << "Unable to open file" << std::endl;

  std::cin.get();
  return 0;
}
