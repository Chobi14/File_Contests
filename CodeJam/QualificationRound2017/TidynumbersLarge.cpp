/* Luis German Paredes Aguilar
Tatiana just finished counting all positive integers
 in ascending order from 1 to N. What was the
  last tidy number she counted?
*/


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int cont = 0;

using namespace std;

string IntToString ( long long num )
{
  ostringstream oss;  
  oss << num;  
  return oss.str();
}

long long StringToInt ( string str )
{
  long long num;
  istringstream ( str ) >> num;
  return num;
}

int main(){
	
	bool flag = 0;
	int min,max,t = 0;int caso = 1;
	char letra = 47;
	
	ifstream Binput;
	Binput.open("BpracticeLarge.in");
	
	ofstream Boutput;
	Boutput.open("BpracticeLargeo.txt");
	
	Binput >> t;
	//cin >> t;
	
	while(t--)	
	{
				
		long long n;
		string s;					
		Binput >> n;
		//cin >> n;
		s = IntToString (n);
				
		if (s.length() == 1)					
		{
			(t == 0) ? Boutput << "Case #" << caso << ": " << n : Boutput << "Case #" << caso << ": " << n << endl;
			//(t == 0) ? cout << "Case #" << caso << ": " << n : cout << "Case #" << caso << ": " << n << endl;
		}else
		{
			for(int i = 0; i < (s.length()-1); i++)
			{							
				if(s[i] > s[i+1])
				{	
					min = i+1;
					letra = s[i];
					max = i;					
					for(int j = min; j < s.length(); j++)
					{						
						s[j] = 57;
					}
					break;					
				}					
			}													
			for(int i = 0; i < min; i++)
			{			
				if(s[i] == letra)
				{
					cont++;					
				}
			}
						
			if(cont==1){
				s[max] -= 1;				
			}else if(cont > 1){
				for(int i = 0; i < cont; i++)
				{
					(i == (cont-1)) ? s[max-i] -= 1 : s[max-i] = 57;
				}
			}			
			
			n = StringToInt(s);
			(t == 0) ? Boutput << "Case #" << caso << ": " << n : Boutput << "Case #" << caso << ": " << n << endl;
			//(t == 0) ? cout << "Case #" << caso << ": " << n : cout << "Case #" << caso << ": " << n << endl;
		}		
		caso++;
	}	
	Binput.close();
	Boutput.close();
	
	return 0;
}
