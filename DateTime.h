#pragma once
#include <iostream>
#include <chrono>
using namespace std;


class TDateTime {
	protected:
		time_t now;
	public:
		TDateTime() {
			now = time(0);
			
		}

		friend ostream& operator<<(ostream& out, const TDateTime& dt) {
			struct tm tstruct = *localtime(&(dt.now));
			char buf[80];
			strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M", &tstruct);
			string date_time = buf;
			out << date_time;
			return out;
		};
};