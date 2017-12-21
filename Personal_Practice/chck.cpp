#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>


//atoi information from  <http://blog.eairship.kr/164>


int main(int argc, char** argv)
{ 
    

	char buff[1000], secNum[100], y;
	int n1, n2, opr;
    std::cout << "Enter the expression. " << std::endl;
    std::cin.getline(buff, 1000);

    /*
    std::string sentence = "string to split";
    std::istringstream iss(sentence);
    //단어를 출력하려면
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         ostream_iterator<string>(cout, "\n"));
    //단어를 container에 저장하려면
    std::vector<string> words;
    std::copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
    //벡터를 바로 생성하려면
    std::vector<string> wordsVector{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
    
    */
    
    for(int i= 0; i < 4; i++)
    {
        secNum[i] = buff[5+i];
        
    }


    n1 = atoi(buff);
    n2=atoi(secNum);
    
    std::cout << n1 + n2 <<std::endl;
    



}