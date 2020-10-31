#include "IteratorFunction.h"
#include "Aitken.h"
#include "Newton.h"
#include "NewtonOriginal.h"
#include "NewtonDownhill.h"
#include "Secant.h"
#include "OnePoint.h"
#include "TwoPoint.h"
#include <iostream>
using namespace std;
int main()
{
    string expression;
    string equivalent;
    double x0;
    double x1;
    int method;
    //method:1-Aitken,2-NewtonOriginal,3-NewtonDownhill,4-OnePoint,5-TwoPoint
    cin >> method;
    cin >> expression;
    cin >> equivalent;
    cin >> x0;
    cin >> x1;
    for(double x = x0 - 1.0; x <= x0 + 1.0; x += 0.01)
    {
        IteratorFunction iterator_function(expression, equivalent, x0, x1, x);
        iterator_function.cal();     
    }
    
    if(method == 1)
    {
    	Aitken aitken(expression, equivalent, x0, x1); 
    	while( fabs(aitken.x - aitken.x1) > YPSILON) 
    	{
			aitken.iterate();    		
		}
   		cout << "The result is " << aitken.x << endl;
	} 
    else if(method == 2)
    {
    	NewtonOriginal newton_original(expression, equivalent, x0, x1);
		while( fabs(newton_original.x - newton_original.x1) > YPSILON) 
    	{
			newton_original.iterate();    		
		}
   		cout << "The result is " << newton_original.x << endl;    	
	}
	else if(method == 3)
	{
		NewtonDownhill newton_downhill(expression, equivalent, x0, x1);	
		while( fabs(newton_downhill.x - newton_downhill.x1) > YPSILON) 
    	{
			newton_downhill.iterate();    		
		}
   		cout << "The result is " << newton_downhill.x << endl;	
	}
	else if(method == 4)
	{
    	OnePoint one_point(expression, equivalent, x0, x1);		
	} 
	else if(method == 5)
	{
		TwoPoint two_point(expression, equivalent, x0, x1);		
	}

	return 0;
}
