#pragma once

#include <string>
#include <iostream>


class time_r
{

  protected:
			short int hour;
			short int minut;
			short int second;
            short int day;

  public:

  		time_r();
		~time_r();

		template <class T>
		void set_visable(T visable_hour, T visable_minut, T visable_second)
		{
			this->visable_hour = visable_hour;
			this->visable_minut = visable_minut;
			this->visable_second = visable_second;
		};

		template <class T>
		void set(T _text)
		{
		 if (this->error_view(_text))
		 {
		 this->manual_time_setting(_text);
		 } else
		 {
			this->set_this_null();
		 };

         this->correct_time();
		};

		template<class T>
		T get_time()
		{
           this->run();
		  T result;

		  if ((this->visable_hour == true) && (this->visable_minut == true) && (this->visable_second == true))
		  {
		   result = std::to_string(this->hour)+":"+std::to_string(this->minut)+":"+std::to_string(this->second);
		   return result;
		  };

		  if ((this->visable_hour == true) && (this->visable_minut == true) && (this->visable_second == false))
		  {
		   result = std::to_string(this->hour)+":"+std::to_string(this->minut);
		   return result;
		  };

		  if ((this->visable_hour == false) && (this->visable_minut == true) && (this->visable_second == true))
		  {
		   result = std::to_string(this->minut)+":"+std::to_string(this->second);
		   return result;
		  };

		};


		int get_hour();
		int get_minut();
		int get_second();
		int get_day();

		void get_visable();
		void run();

		void forward();
		void back();

		void set_forward(bool&& forward_or_back);

  private:
			bool visable_hour;
			bool visable_minut;
			bool visable_second;
			bool format_hour_12;

			bool forward_b;

			//------------const--------------
			const short int hour_l_sh               = 2;
			const short int hour_l_l                = 3;
			const short int minut_l                 = 2;
			const short int second_l                = 3;
			const short int absolut_length_short    = 7;
			const short int absolut_length_long     = 8;
			//------------------------------

			short int get_how_length(bool long_hour);
			short int get_how_colon();


		 bool error_view(std::string& time);
		 bool error_view_leng(std::string& time, short int hour_s_l);
		 bool error_view_colon(std::string& time);
         bool plug_the_null();

		 void manual_time_setting(std::string& _text);
		 void automatics_time_setting(std::string& _text, bool&& hour_short);

		 void set_this_null();
         void correct_time();


		 template<typename T>
		 T get_null(short int& item)
		 {

		   T result;
		   if (item < 10)
		   {
			result = "0"+std::to_string(item);
		   } else
		   {
			result = std::to_string(item);
		   };


		   return result;

		 };


};
