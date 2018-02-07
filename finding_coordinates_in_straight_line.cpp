#include <iostream>
#include <math.h>


using namespace std;

int main() {
    
    int x1,y1,x2,y2,num_of_coordinate=0;
    cin>>x1>>y1>>x2>>y2;
    cin>>num_of_coordinate;
    
    double diff_a=abs(x1-x2);
    double diff_b=abs(y1-y2);
    
    if(x2<x1)
     diff_a*=-1;
     
    if(y2<y1)
     diff_b*=-1;
     
    
    for(double x=x1,y=y1,z=0; z<=num_of_coordinate; x+=(diff_a/num_of_coordinate),y+=(diff_b/num_of_coordinate),z++)
    {
    	cout<<x<<" "<<y<<endl;
    }
    
}
