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

	for (int i = 0; i < 9; i++)
	{
	 p.run();
	}


     p.get_visable();



	std::system("pause");
	return 0;
}
