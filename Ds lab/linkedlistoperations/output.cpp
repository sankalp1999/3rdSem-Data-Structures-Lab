#include <iostream>
using namespace std;
int main (){
		char c='z';
		char *pc=&c;
// sizeof returns the # of bytes…
    cout<<"\n pc= "<<pc<< " sizeof(pc): "<<sizeof(pc);
    cout<<"\n *pc= "<<*pc<<" sizeof(*pc): "<<sizeof(*pc);
    cout<<"\n &pc= "<<&pc<<" sizeof(&pc): "<<sizeof(&pc);
	return 0;
}
