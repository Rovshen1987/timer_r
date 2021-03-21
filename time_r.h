#pragma once

#include <string>
#include <iostream>


class time_r
{

  public:
			short int hour;
			short int minut;
			short int second;

		time_r();
		~time_r();

		template <class T>
		void set_visable(T visable_hour, T visable_minut, T visable_second)
		{
			this->visable_hour = visable_hour;
			this->visable_minut = visable_minut;
			this->visable_second = visable_second;
		};

		void get_visable();
		void run();

  private:
			bool visable_hour;
			bool visable_minut;
			bool visable_second;
			bool format_hour_12;

			short int* error_view_length;
			short int* error_view_dot;

			//------------const--------------
			const short int hour_l_sh   = 2;
			const short int hour_l_l    = 3;
			const short int minut_l     = 2;
			const short int second_l    = 3;
			//------------------------------

			short int get_how_length(bool long_hour);
			short int get_how_colon();

		 bool error_view(std::string& time);
         void push_doc();

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
