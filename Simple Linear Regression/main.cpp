/*
    Simple Linear Regression Algorithm
        - Gradient Descent

    Date: 26 December, 2019
    Author ~ Aman Agarwal
*/

#include<iostream>
#include<math.h>

using namespace std;

template <class T>
class LinearRegression
{
private:
    // Input Values
    T *X;
    // Output Values
    T *Y;
    // Hypothesis
    T *H;
    // Number of training sets
    long int m;
    // Y-intercept
    T theta0;
    // Slope
    T theta1;
public:
    LinearRegression()
    {
        X = nullptr;
        Y = nullptr;
        H = nullptr;
    }
    // Get the Dataset from the user
    void getDataset(void);
    // Allocate Memory for the dataset
    void allocateMemory(void);
    // Find theta0 and theta1 using Gradient Descent Algorithm
    void gradientDescent(void);
    // Find the predicted value of x(i) i.e hthetax(i) or f(x) or hypothesis
    void hypothesis(void);
    // Minimum Squared Error or Cost Function
    T costFunction(void);
    // Predict Values
    void predictValues(void);
};

// Get the Dataset
template <class T>
void LinearRegression<T>::getDataset(void)
{
    cout << "Enter the total number of training examples: ";
    cin >> this->m;

    allocateMemory();

    for(int i = 0; i < this->m; i++)
    {
        cout << "Enter the values of (X, Y):\n";
        cin >> this->X[i];
        cin >> this->Y[i];
    }
}

// Find theta0 and thet1 using the Gradient Descent Algorithm
template <class T>
void LinearRegression<T>::gradientDescent(void)
{
    // Declaration of variables
    T dt0, dt1, cost, oldCost;
	T oldTheta0, oldTheta1;
    float learningRate = 1;
	int step = 0;

    // initializing theta0 and theta1 to 0
	this->theta0 = 0, this->theta1 = 0;

    while(1)
    {
        dt0 = 0;
        dt1 = 0;

        // finding the cost of oldtheta
		oldTheta0 = this->theta0;
		oldTheta1 = this->theta1;
        hypothesis();
        oldCost = costFunction();

        // finding the derivatives
        for(int j = 0; j < this->m; j++)
        {
            dt0 = dt0 + ((this->H[j] - this->Y[j]) * 1/this->m);
            dt1 = dt1 + (((this->H[j] - this->Y[j]) * this->X[j]) * 1/this->m);    
        }

        // finding the cost of new theta
        this->theta0 = this->theta0 - (learningRate * dt0);
        this->theta1 = this->theta1 - (learningRate * dt1);
		hypothesis();
		cost = costFunction();

        //comparing oldcost to newcost
		if(cost > oldCost)
		{
			this->theta0 = oldTheta0;
			this->theta1 = oldTheta1;
			cout << this->theta0 << "\t" << this->theta1 << "\t" << oldCost << "\t" << step++ << endl;
			break;
		}
		else if(abs(cost - oldCost) <= 0.001)
		{
			 cout << this->theta0 << "\t" << this->theta1 << "\t" << cost << "\t" << step++ << endl;
		}
    }
    predictValues();
}

// Find the predicted value of x(i) i.e htheta(x)(i) or f(x) or hypothesis
template <class T>
void LinearRegression<T>::hypothesis(void)
{
    // y = mx + c OR htheta(x) = theta0 + theta1 * x(i)
    for(int i = 0; i < this->m; i++)
        this->H[i] = this->theta0 + (this->theta1 * this->X[i]);
}

// Cost Function or Minimum Squared Error
template <class T>
T LinearRegression<T>::costFunction(void)
{
    T cost = 0;
    for(int i = 0; i < this->m; i++)
        cost += pow(abs(this->H[i] - this->Y[i]), 2);
    cost/= (2 * this->m);

    return cost;
}

// Predict Values
template <class T>
void LinearRegression<T>::predictValues(void)
{
    cout << "Theta0 = " << this->theta0 << endl;
    cout << "Theta1 = " << this->theta1 << endl;

    for(int i = 0; i < this->m; i++)
    {
        this->H[i] = this->theta0 + (this->theta1 * this->X[i]);
        cout << this->X[i] << " = " << this->H[i] << endl;
    }
}

// Allocate Memory 
template <class T>
void LinearRegression<T>::allocateMemory(void)
{
    this->X = new(nothrow) T[this->m];
    this->Y = new(nothrow) T[this->m];
    this->H = new(nothrow) T[this->m];

    if(this->X == nullptr || this->Y == nullptr || this->H == nullptr)
    {
        cout << "Failed to Allocate Memory\n";
        exit(1);
    }
}

int main()
{
    LinearRegression <float> lr;

    lr.getDataset();
    lr.gradientDescent();

    return 0;
}