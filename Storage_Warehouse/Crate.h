#ifndef CRATE_H
#define CRATE_H
using namespace std;

class Crate
{
	private:
		int weight;
		int number;
		bool transported;
		string priority;

	public:
		
		Crate(int i);

		void TakeCrate(int i);

		void printCrate();
		
		string checkPriority();
		
		bool checkTransport();

		~Crate();
};

#endif
