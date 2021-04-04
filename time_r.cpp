
#include "time_r.h"


 time_r::time_r():day(0), hour(0), minut(0), second(0), visable_hour(true), visable_minut(true),
				   visable_second(true), format_hour_12(false), forward_b(true)
				   {

				   };

 time_r::~time_r()
 {
   this->hour   = 0;
   this->minut  = 0;
   this->second = 0;

 };

 bool time_r::error_view(string& time)
 {
	bool length = false;
	bool colon  = false;

	 if (time.length() == absolut_length_short)
	 {
	 length = this->error_view_leng(time, absolut_length_short);
	 } else
	 if (time.length() == absolut_length_long)
	 {
	 length = this->error_view_leng(time, absolut_length_long);
	 } else
	 {
	  length = false;
	 };

	 colon =   this->error_view_colon(time);

	   if ((length == true) && (colon == true))
	  {
	   return true;

	  } else
	  {
	   return false;
	  };

 };

bool time_r::error_view_leng(string& time, short int hour_s_l)
{

	 if (time.length()==hour_s_l)
	 {
	   return true;
	 } else
	 {
	   return false;
	 };
};

bool time_r::error_view_colon(string& time)
{
   short int result = 0;

  for (int i = 0; i <= time.length(); i++)
  {
	 if (time[i]==':')
	 {
	   result ++;
	 }
  };


  if (result == get_how_colon())
  {
	return true;
  } else
  {
    return false;
  }
};


void time_r::get_visable()
{
	 std::cout << std::boolalpha<< "hour   = " << (this->visable_hour)
	 <<";\nminut  = " << this->visable_minut << ";\nsecond = " <<this->visable_second << "; \n";
};


void time_r::run()
{

   if (this->forward_b)
   {
	 this->second++;
	 this->forward();
   } else
   {
	 if (this->plug_the_null())
	 {
	 this->second--;
	 this->back();
	 };

   };
};



short int time_r::get_how_length(bool long_hour)  //this function for the set
{
  short int result = 0;

  if (visable_hour)
  {
	if (long_hour)
	{
	 result += this->hour_l_l;
	} else
	{
	 result += this->hour_l_sh;
	};
  };


  if (visable_minut)
  {
	 result += this->minut_l;
  };

  if (visable_second)
  {
	 result += this->second_l;
  };

  return result;
};

short int time_r::get_how_colon() //this function for the set
{
  short int result = 0;

  if (this->visable_hour)
  {
	 result++;
  };


  if (this->visable_minut)
  {
	 result++;
  };

  if (this->visable_second)
  {
	 result++;
  };


switch(result)
{

case 2: {
		 return 1;
		 break;
		};

case 3: {
		 return 2;
		 break;
		};

default: {
		  return 0;
		  break;
         };

};

};


void time_r::manual_time_setting(string& _text)
{

	   if (_text.length() == this->absolut_length_short)
	   {
		this->automatics_time_setting(_text, true);
	   } else
		 if (_text.length() == this->absolut_length_long)
		 {
		  this->automatics_time_setting(_text, false);
		 } else
		 {
         this->set_this_null();
		 }

};

void time_r::automatics_time_setting(string& _text, bool&& hour_short)
{
 short int hour_m = 0;
 short int minut_m = this->minut_l;
 short int second_m = this->second_l;

 if (hour_short)
 {
  hour_m = this->hour_l_sh;
 } else
 {
  hour_m = this->hour_l_l;
 };


 hour_m--;

  { //hour
	string temp = "";

   for (int i = 0; i < hour_m; i++)
   {
	 temp = temp + _text[i];
   };
	 this->hour = std::stoi(temp);
   }


  { //minut
	string temp = "";

   for (int i = (hour_m+1); i < ((hour_m+1)+minut_m); i++)
   {
	 temp = temp + _text[i];
   };
	 this->minut = std::stoi(temp);
   }

  { //second
	string temp = "";

   for (int i = ((hour_m+1)+(minut_m+1)); i < ((hour_m+1)+(minut_m+second_m)); i++)
   {
	 temp = temp + _text[i];

   };
	 this->second = std::stoi(temp);
   }
};


int time_r::get_hour()
{
   return this->hour;
};

int time_r::get_minut()
{
   return this->minut;
};

int time_r::get_second()
{
   return this->second;
};

void time_r::set_this_null()
{
	this->hour = 0;
	this->minut = 0;
	this->second = 0;
};

void time_r::correct_time()
{
	  if (this->hour > 24)
	  {
		this->hour = 24;
	  };

	  if (this->minut > 59)
	  {
		this->minut = 59;
	  };

	  if (this->second > 59)
	  {
		this->second = 59;
	  };
};


int time_r::get_day()
{
   return this->day;
};


void time_r::forward()
{
   if ((this->hour == 24) && (this->minut == 59) && (this->second > 59) )
   {
	 this->day++;
	 this->set_this_null();

   };

   if ((this->hour < 24) && (this->minut == 59) && (this->second > 59) )
   {
	 this->hour++;
	 this->minut  = 0;
	 this->second = 0;
   };

   if ((this->hour < 24) && (this->minut < 59) && (this->second > 59) )
   {
	 this->minut++;
	 this->second = 0;
   };

};

void time_r::back()
{

   if ((this->hour > 0) && (this->minut <= 0) && (this->second < 0) )
   {
	 this->hour--;
	 this->minut =  59;
	 this->second = 59;

   };

   if ((this->hour > 0) && (this->minut > 0) && (this->second < 0) )
   {
	 this->minut--;
	 this->second = 59;
   };

};

void time_r::set_forward(bool&& forward_or_back)
{
	this->forward_b = forward_or_back;
};

bool time_r::plug_the_null()
{
  	  if ((this->hour <= 0) && (this->minut <= 0) && (this->second <= 0) )
	  {
        this->second = 0;
		return false;
	  } else
	  {
		return true;
	  };
};


string time_r::create_null_text(const short int watch)
{
  string result;
  if ((watch >= 0) && (watch < 10))
  {
  result = "0";

  };

  result = result + std::to_string(watch);

  return result;
}


 string time_r::get_time()
{
 this->run();
 string result;

 if ((this->visable_hour == true) && (this->visable_minut == true) && (this->visable_second == true))
 {
 result = std::to_string(this->hour)+":"+create_null_text(this->minut)+
		":"+create_null_text(this->second);
 return result;
 };

 if ((this->visable_hour == true) && (this->visable_minut == true) && (this->visable_second == false))
 {
 result = create_null_text(this->hour)+":"+create_null_text(this->minut);
 return result;
 };

 if ((this->visable_hour == false) && (this->visable_minut == true) && (this->visable_second == true))
 {
 result = create_null_text(this->minut)+":"+create_null_text(this->second);
 return result;
 };

 return result;

 };
