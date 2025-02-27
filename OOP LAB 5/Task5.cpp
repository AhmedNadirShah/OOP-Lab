#include <iostream>

using namespace std;

class Car {
public:
	int engine_horsepower, seating_capacity, no_of_speakers;


	void modify() const {

		Car* self = const_cast<Car*>(this);
		self->engine_horsepower = 300;
		self->seating_capacity = 5;
		self->no_of_speakers = 8;
	}
};

int main(int argc, char* argv[]) {
	if (argc < 4) {
		cout << "Usage: " << argv[0] << " <horsepower> <seats> <speakers>\n";
		return 1;
	}

	Car car;
	car.engine_horsepower = atoi(argv[1]);
	car.seating_capacity = atoi(argv[2]);
	car.no_of_speakers = atoi(argv[3]);

	car.modify();

	cout << "Horsepower: " << car.engine_horsepower << "\n"
	     << "Seats: " << car.seating_capacity << "\n"
	     << "Speakers: " << car.no_of_speakers << "\n";
}
