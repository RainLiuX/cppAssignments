#include <iostream>
#include <string>

// base class
class Package {
	friend std::ostream& operator<<(std::ostream& os, const Package& pkg);
public:
	Package(): weight(0.0f) {}
	Package(const std::string& r, const std::string& ad, const std::string& c, const std::string& pro, const std::string code, float w) :
		receiver(r), address(ad), city(c), province(pro), postCode(code), weight(w) {}
	virtual float calculateCost() = 0;
protected:
	std::string receiver;
	std::string address;
	std::string city;
	std::string province;
	std::string postCode;
	float weight;
}; 

// inherited classes
class ThreeDayPackage: virtual public Package {
	static float threeDayCost;
public:
	ThreeDayPackage(const std::string& r, const std::string& ad, const std::string& c, const std::string& pro, const std::string code, float w) :
		Package(r, ad, c, pro, code, w) {}
	float calculateCost() { return weight * threeDayCost; }
};

class OverNightPackage: virtual public Package {
	static float overNightCost;
public:
	OverNightPackage(const std::string& r, const std::string& ad, const std::string& c, const std::string& pro, const std::string code, float w) :
		Package(r, ad, c, pro, code, w) {}
	float calculateCost() { return weight * overNightCost; }
};

// inplimentations
float ThreeDayPackage::threeDayCost = 1;
float OverNightPackage::overNightCost = 2;

std::ostream& operator<<(std::ostream& os, const Package& pkg) {
	os << "receiver: " << pkg.receiver << std::endl
		<< "address: " << pkg.address << std::endl
		<< "city: " << pkg.city << std::endl
		<< "province: " << pkg.province << std::endl
		<< "postCode: " << pkg.postCode << std::endl
		<< "weight: " << pkg.weight << std::endl;
	return os;
}

int main() {
	using namespace std;
	Package* p = new ThreeDayPackage("Jiang Yankai", "New Rimuli", "Xi'an", "Shaanxi", "710049", 300.4);
	cout << "p is a three-day-package" << endl;
	cout << "total cost " << p->calculateCost() << endl;
	cout << *p << endl;
	p = new OverNightPackage("Li Jingyi", "XJTU", "Shijiazhuang", "Hebei", "123459", 5.4);
	cout << "p is a over-night-package" << endl;
	cout << "total cost " << p->calculateCost() << endl;
	cout << *p << endl;
	return 0;
}
