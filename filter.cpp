
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/*
int main(int argc, char* argv[]) {

	string filename;

	if (argv[argc] = nullptr) {

		cout << "Invalid file name.Exiting...";

		return 0;
	}
	else {

		filename = argv[argc-1];
	}

	//filename = "C:/\\Users\//geo-lev\//Desktop\//ExampleImages\//Image02.ppm";

	Image img;
	
	img.load(filename, "ppm");

	/*
	FilterGamma filtergamma( 2.0 );

	cout << "gamma check";

	img = filtergamma << img;

	cout << "linear check";


	math::Vec3<float> a, c;


	a.r = -1;
	a.g = -1;
	a.b = -1;

	c.r = 1;
	c.g = 1;
	c.b = 1;

	FilterLinear filterlinear(a, c);

	img = filterlinear << img;

	

	for (int i = 1; i < argc; i ++) {

		if (string(argv[i]) == "-f") {

			if (string(argv[i + 1]) == "gamma") {

				FilterGamma filter(stof(argv[i + 2], nullptr));

				cout << "gamma check";

				img = filter << img ; 
			}

			if (string(argv[i + 1]) == "linear") {


				cout << "linear check";
				math::Vec3<float> a, c;


				a.r = stof(argv[i + 2]);
				a.g = stof(argv[i + 3]);
				a.b = stof(argv[i + 4]);

				c.r = stof(argv[i + 5]);
				c.g = stof(argv[i + 6]);
				c.b = stof(argv[i + 7]);
				
				FilterLinear filter(a, c);

				img = filter << img;
			}
		}
	}



	cout << img.getHeight() << endl << img.getWidth() << endl;
	
	system("pause");

	size_t found = filename.find_last_of("/\\ ") ;

	filename = filename.substr(found + 1);

	filename = "filtered_" + filename;


	cout << filename;

	img.save(filename, "ppm");

}*/