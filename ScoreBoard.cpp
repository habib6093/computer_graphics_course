#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


class scoreBoard{
 public:
     scoreBoard()
     {
         player_name="";
         score=0;
     }
     string player_name;
     double score;
};



bool checkCondition(scoreBoard ob1,scoreBoard ob2)
{
    return ob1.score>ob2.score;
}



void saveScore(string player_name,double score)
{
  ofstream myfile("example.txt",ios::out | ios::app);
  myfile << player_name<<" "<<score<<"\n";
  myfile.close();
}





void getTopScore(scoreBoard ob[],int how_many)
{
      string line;
      int counter=0;
      scoreBoard temp[500];

      ifstream myfile ("example.txt");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
            stringstream ss;
            string name;
            double score;
            ss<<line;
            ss>>name>>score;

            temp[counter].player_name=name;
            temp[counter].score=score;

            counter++;
        }
        myfile.close();
      }

      sort(temp,temp+counter,checkCondition);

      for(int i=0;i<how_many;i++)
      {
          ob[i]=temp[i];
      }
}


int main () {

  saveScore("Rahim",10);  ///pass name and score as parameter
  saveScore("Rahman",70);
  saveScore("Minar",5);

  int how_many_score=2;
  scoreBoard ob[how_many_score]; /// create scoreboard object array...
  getTopScore(ob,how_many_score);  /// pass the object and how many score you need..

  for(int i=0;i<how_many_score;i++)
    cout<<"player name: "<<ob[i].player_name<<"  score: "<<ob[i].score<<endl;   ///if there aren't enough scores in file,objects variables value will be "" and 0


  return 0;
}



//output////

//player name: Rahman  score: 70
//player name: Rahim  score: 10





