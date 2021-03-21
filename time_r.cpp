
#include "time_r.h"


 time_r::time_r():hour(0), minut(0), second(0), visable_hour(true), visable_minut(true),
				   visable_second(true), format_hour_12(false)
				   {
					 this->error_view_length = new short int{0};
					 this->error_view_dot = new short int{0};
				   };

 time_r::~time_r()
 {
   this->hour   = 0;
   this->minut  = 0;
   this->second = 0;


  delete this->error_view_length;
  delete this->error_view_dot;


 };

 bool time_r::error_view(std::string& time)
 {
	int result = 0;
	int length = time.length();

	  for (char i: time)
	  {
		if (i == ':')
		result++;


	  };

	  if ((result==2) && (length == 8))
	  {
	   return true;
	  } else
	  {
       return false;
	  }
 };


void time_r::get_visable()
{
	 std::cout << std::boolalpha<< "hour = " << (this->visable_hour)
	 <<";\n minut = " << this->visable_minut << ";\n second = " <<this->visable_second << "; \n";
	 std::string s;
	 s = this->get_null<std::string>(this->second);
	 std::cout << s << std::endl;
};


void time_r::run()
{
	 if ((this->second>59) && (this->minut==59) && (this->hour==24))
	 {
	  this->second = 0;
	  this->minut  = 0;
	  this->hour   = 0;
	 }

	 if ((this->second>59) && (this->minut==59) && (this->hour<24))
	 {
	  this->second = 0;
	  this->minut  = 0;
	  this->hour++;
	 }

	 if ((this->second>59) && (this->minut<59) && (this->hour<24))
	 {
	  this->second = 0;
	  this->minut++;
	 }

     this->second++;
};


void time_r::push_doc()
{
	if (this->visable_hour)
	{
	  *this->error_view_length = 2;
	  *this->error_view_dot = 1;
	};

		if (this->visable_minut)
	{
	  *this->error_view_length = *this->error_view_length+2;
	};

			if (this->visable_second)
	{
	  *this->error_view_length = *this->error_view_length+3;
	  *this->error_view_dot   = *this->error_view_dot+1;
	};

};


