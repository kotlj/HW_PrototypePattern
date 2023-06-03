
#include <iostream>
#include <string>

class Venchile
{
protected:
	int EnginePower;
public:
	Venchile()
	{
		EnginePower = 10;
	}
	Venchile(int _EnginePower)
	{
		EnginePower = _EnginePower;
	}
	virtual Venchile* clone() = 0;
};

class Car : protected Venchile
{
private:
	int doors;
public:
	Car(int _doors) : Venchile(40)
	{
		doors = _doors;
	}
	Car* clone() override
	{
		Car* temp = new Car(doors);
		return temp;
	}
};
class Motorcycle : protected Venchile
{
private:
	std::string model;
public:
	Motorcycle(std::string _model) : Venchile(45)
	{
		model = _model;
	}
	void sound()
	{
		std::cout << "Brr-r-r-r!\n";
	}
	Motorcycle* clone() override
	{
		Motorcycle* temp = new Motorcycle(model);
		return temp;
	}
};
class Bus : protected Venchile
{
private:
	int MaxPassagers;
public:
	Bus(int _MaxPassagers) : Venchile(70)
	{
		MaxPassagers = _MaxPassagers;
	}
	void Stop()
	{
		std::cout << "All grab something! We`re stopping!\n";
	}
	Bus* clone() override
	{
		Bus* temp = new Bus(MaxPassagers);
		return temp;
	}
};

int main()
{
	Bus* test;
	Bus bus(40);
	test = bus.clone();
	test->Stop();
}