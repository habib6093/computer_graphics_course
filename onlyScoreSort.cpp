#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string scores[5]={};


bool checkCondition(double a,double b)
{
    return a>b;
}


void saveScores()
{
  ofstream myfile("example.txt",ios::out | ios::app);

  for(int i=0;i<5;i++)
  {
      myfile <<scores[i]<<"\n";
  }
  myfile.close();
}





void getTopScores()
{
      string line;
      int counter=0;
      double temp_scores[50]={};

      ifstream myfile ("example.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
            stringstream ss;
            double score;
            ss<<line;
            ss>>temp_scores[counter];

            counter++;
        }
        myfile.close();
      }

      sort(temp_scores,temp_scores+counter,checkCondition);

      for(int i=0;i<5;i++)
      {
          stringstream sd;
          sd<<temp_scores[i];
          scores[i]=sd.str();
      }
}






int main () {

     scores[0]="0";
     scores[1]="50";
     scores[2]="30";
     scores[3]="5";
     scores[4]="25.5";


     saveScores();  
     getTopScores();

     for(int i=0;i<5;i++)
        cout<<scores[i]<<endl;

  return 0;
}


