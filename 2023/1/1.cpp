#include <iostream>
#include <fstream>
#include <string>

int main(){
  std::ifstream file;
  file.open("input.txt");

  std::string line;
  if(file.is_open()){
    int sum = 0;
    while(getline(file, line)){
      int l=0;
      int r=line.size()-1;
      while(l<=r && (!isdigit(line[l]) || !isdigit(line[r]))){
        if(!isdigit(line[l])) l++;
        if(!isdigit(line[r])) r--;
      }

      std::string numStr;
      numStr += line[l];
      numStr += line[r];
      int num = stoi(numStr);
      sum += num;
      std::cout << line[l]<<" "<<line[r]<<" "<<sum << "\n";
    }

    file.close();
  }else std::cout << "unable to open file";

  std::cin.get();
  return 0;
}
