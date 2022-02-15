/*
Copyright (c) Cohen ter Heide 2014-2022 All rights reserved.
This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
Cohen ter Heide
support@lumpology.com
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream openversionfile;
	ofstream outputversionfile;
	string filereader;
	string userargs;
	cout<<"Type _version for current FC version."<<endl;
	cout<<"Type _set to define a new FC version."<<endl;
	cout<<"Type _exit or _compile to exit tool."<<endl;
	do {
		cout<<"VersionShell~ ";
		cin>>userargs;
		if (userargs=="_version") {
			openversionfile.open("var_z/version.h");
			getline(openversionfile, filereader);
			cout<<"Current Version Code: "<<filereader<<endl;
			openversionfile.close();
		} else if (userargs=="_set") {
			cout<<"Type New Version String: ";
			cin>>userargs;
			outputversionfile.open("var_z/version.h");
			outputversionfile<<"string fc_version = \""<<userargs<<"\";";
			outputversionfile.close();
			cout<<"string fc_version = \""<<userargs<<"\";"<<endl;
		} else if (userargs=="_exit"||userargs=="_compile") {
			break;
		} else {
			cout<<"Error["<<userargs<<"] is not a valid command."<<endl;	
		}
	} while (true);
	openversionfile.close();
	outputversionfile.close();
	return 0;
}
