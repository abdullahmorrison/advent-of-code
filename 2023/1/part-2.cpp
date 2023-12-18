#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int getNum(std::string line, int i){
  std::unordered_map<char, std::vector<std::string>> letterToNum;
  letterToNum['o'] = {"one"};
  letterToNum['t'] = {"two", "three"};
  letterToNum['f'] = {"four", "five"};
  letterToNum['s'] = {"six", "seven"};
  letterToNum['e'] = {"eight"};
  letterToNum['n'] = {"nine"};

  std::unordered_map<std::string, int> strToNum;
  strToNum["one"] = 1;
  strToNum["two"] = 2;
  strToNum["three"] = 3;
  strToNum["four"] = 4;
  strToNum["five"] = 5;
  strToNum["six"] = 6;
  strToNum["seven"] = 7;
  strToNum["eight"] = 8;
  strToNum["nine"] = 9;


  for(auto it = letterToNum.begin(); it != letterToNum.end(); it++){
    for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
      if(line.substr(i, it2->size()) == *it2){
        return strToNum[*it2];
      }
    }
  }
  
  return -1;
}
int main(){
  std::ifstream file;
  file.open("input.txt");

  std::string line;
  if(file.is_open()){
    try{
      int sum = 0;
      while(std::getline(file, line)){
        int l=0;
        int r=line.size()-1;

        int lNum = getNum(line, l);
        int rNum = getNum(line, r);
        while(l<r 
            && (!isdigit(line[l]) && lNum==-1 
              || !isdigit(line[r]) && rNum==-1)
        ){
          lNum = getNum(line, l);
          rNum = getNum(line, r);

          if(!isdigit(line[l]) && lNum==-1) l++;
          if(!isdigit(line[r]) && rNum==-1) r--;
        }

        int numStr = 0;
        if(isdigit(line[l])) numStr = line[l]-'0';
        else numStr = lNum;


        if(isdigit(line[r])) numStr = numStr*10 + line[r]-'0';
        else numStr = numStr*10 + rNum;
        

        sum += numStr;
        std::cout << sum << "\n";
      }
    }catch(std::exception& e){
      std::cout << "error: "<< e.what() << "\n";
    }
    file.close();
  }
  else std::cout << "Unable to open file" << std::endl;

  std::cout << "Done!";

  std::cin.get();
  return 0;
}
