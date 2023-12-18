#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief concatenates the first and last digit of a string
 * @param a string of letters and numbers
 * @return a 2 digit number
 */
int getNum(std::string str){
  int l=0;
  int r=str.size()-1;
  while(l<=r && (!isdigit(str[l]) || !isdigit(str[r]))){
    if(!isdigit(str[l])) l++;
    if(!isdigit(str[r])) r--;
  }
  return (str[l]-'0')*10 + (str[r]-'0');
}

int main(){
  std::ifstream file;
  file.open("input.txt");

  std::string line;
  if(file.is_open()){
    int sum = 0;
    while(getline(file, line)){
      sum += getNum(line);
    }
 
    std::cout << sum;

    file.close();
  }else std::cout << "unable to open file";

  std::cin.get();
  return 0;
}
