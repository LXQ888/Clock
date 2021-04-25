#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

class CLOCK
{
	private:
		int Hour;
		int Minute;
		int Second;
	public:
		void Set(int h,int m,int s)
		{
			Hour=(h>=0&&h<=24)?h:0;
			Minute=(m>=0&&m<=60)?m:0;
			Second=(s>=0&&s<=60)?s:0;
		}
		void Run()
		{
			int i=0;
			for(i=0;i<86400;i++)
			{
				Second++;
				if(Second>=60)
				{
					Second=0;
					Minute++;
					if(Minute>=60)
					{
						Minute=0;
						Hour++;
						if(Hour>=24)
						{
							Hour=0;
						}
					}
				}
				cout<<'\r';
				Sleep(1000);
				Show();
				Report();
			}
		}
		void Show()
		{
			cout<<" "<<" "<<"钟表：";
			if(Hour<10)
			{
				cout<<0<<Hour;
			}
			else
			{
				cout<<Hour;
			}
			cout<<":";
			if(Minute<10)
			{
				cout<<0<<Minute;
			}
			else
			{
				cout<<Minute;
			}
			cout<<":";
			if(Second<10)
			{
				cout<<0<<Second;
			}
			else
			{
				cout<<Second;
			}
		}
		void Report();
 } ;
 


	void CLOCK::Report()
	{
		if(Minute==0&&Second==0)
		{
			for(int i=0;i<Hour;i++)
			{
				cout<<'\007';
				Sleep(1000);
				Second++;
				cout<<'\r';
				Show();
			}
		}
	}



 int main()
 {
 	CLOCK c1;
 	c1.Set(0,0,0);
 	c1.Run();
 	return 0;
 }
