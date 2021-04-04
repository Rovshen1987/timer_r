#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include "time_r.h"

int _tmain(int argc, _TCHAR* argv[])
{

	 time_r p;
	 p.set<std::string>("0:1:15");
	 p.set_forward(false);
     p.get_visable();

	 std::string s;
 for (int i = 0; i < 100; i++)
	 {
	   s = p.get_time();

		std::cout << s << std::endl;
	 }

	 std::cout << p.get_hour() <<
			   " \n"<< p.get_minut() <<
			   " \n"<< p.get_second() <<
			   " \n"<<p.get_day() << std::endl;





	std::system("pause");
	return 0;
}
