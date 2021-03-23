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
	 p.set<std::string>("31:79:83");

	 std::cout << p.get_hour() <<
			   " \n"<< p.get_minut() <<
               " \n"<< p.get_second() << std::endl;



	std::system("pause");
	return 0;
}
