#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double mul(double x, double xi, double xk)
{
    return ((x - xi) / (xk - xi));
}

// Finds Lagarangee multuplier
double li(int numOfPoints, int j, double xvals[], double x)
{
    double p = 1;
    for (int i = 0; i < numOfPoints; i++)
    {
        if (i == j)
        {
            continue;
        }
        else
        {
            p *= mul(x, xvals[i], xvals[j]);
        }
    }
    return p;
}

/*Returns sum required for derivative of Langrangee term*/
double sum(int numOfPoints, int j, double xvals[])
{
    double p = 0;
    for (int i = 0; i < numOfPoints; i++)
    {
        if (i == j)
        {
            continue;
        }
        else
        {
            p += xvals[i];
        }
    }
    return p;
}
double mul2(double xk, double xi)
{
    return (xk - xi);
}

/*Gives output of derivative of Langrangee*/
double lid(int numOfTerms, double x, int j, double sumTerm, double xvals[])
{
    double a, b = 1;
    /*to calculate b*/
    for (int i = 0; i < numOfTerms; i++)
    {
        if (i == j)
        {
            continue;
        }
        else
        {
            b *= mul2(xvals[j], xvals[i]);
        }
    }
    /*Calculte Ldash as whole*/
    for (int i = 0; i < numOfTerms; i++)
    {
        if (i == j)
        {
            continue;
        }
        else
        {
            a = (2 * x) - (sum(numOfTerms, j, xvals));
        }
    }
    return a / b;
}
/*work here hermite coefff is remaining.....*/
/*Hermite coeff*/
// returns Hni
double hi(int numOfTerms, double x, double xvals[], int j)
{
    double g = li(numOfTerms, j, xvals, x);
    double h = lid(numOfTerms, xvals[j], j, sum(numOfTerms, j, xvals), xvals);
    double ans = (1 - (2 * (x - xvals[j]) * (h))) * (pow(g, 2));
    return ans;
}

// returns Hnihat
double hiHat(int numOfTerms, double x, double xvals[], int j)
{
    double g = li(numOfTerms, j, xvals, x);
    double ans = (x - xvals[j]) * (pow(g, 2));
    return ans;
}

int main()
{
    int n; // n stands for number of data points
    double x;
    cout << "Enter number of data points given (n):-  ";
    cin >> n; // Input n
    cout << "Enter x: ";
    cin >> x; // Input x

    // Here values of the data points are hardcoded......
    double xval[n] = {1.3, 1.6, 1.9};                       // values of xi
    double yval[n] = {0.6200860, 0.4554022, 0.2818186};     // values of fi
    double ydval[n] = {-0.5220232, -0.5698959, -0.5811571}; // values of f'i

    /*Uncomment lines 31 to 42 to print the input arrays*/

    // below lines print the array xval, yval and ydval
    cout << "values of xi : ";
    for (int i = 0; i < 3; i++)
    {
        cout << xval[i] << "  ";
    }
    cout << endl;
    cout << "values of fi : ";
    for (int i = 0; i < 3; i++)
    {
        cout << yval[i] << "  ";
    }
    cout << endl;
    cout << "values of f'i : ";
    for (int i = 0; i < 3; i++)
    {
        cout << ydval[i] << "  ";
    }
    cout << endl;

    // /*Uncomment to print values of corresponding hi and hiHat*/

    cout << "Value of Hn,0(x) at x = 1.5 : " << hi(n, 1.5, xval, 0);
    cout << endl;
    cout << "Value of H^n,0(x) at x = 1.5 : " << hiHat(n, 1.5, xval, 0);
    cout << endl;
    cout << "Value of Hn,1(x) at x = 1.5 : " << hi(n, 1.5, xval, 1);
    cout << endl;
    cout << "Value of H^n,1(x) at x = 1.5 : " << hiHat(n, 1.5, xval, 1);
    cout << endl;
    cout << "Value of Hn,2(x) at x = 1.5 : " << hi(n, 1.5, xval, 2);
    cout << endl;
    cout << "Value of H^n,2(x) at x = 1.5 : " << hiHat(n, 1.5, xval, 2);
    cout << endl;

    // towrads getting final answer: hi*fi and sum is found
    double fin1 = 0;
    for (int i = 0; i < n; i++)
    {
        fin1 += yval[i] * hi(n, x, xval, i);
    }

    // towrads getting final answer: hiHat*fidash and sum is found
    double fin2 = 0;
    for (int i = 0; i < n; i++)
    {
        fin2 += ydval[i] * hiHat(n, x, xval, i);
    }
    // Final Answer is found by adding both values

    double finalAns = (fin1 + fin2);

    cout << "Value of Hermite Polynomial at x = " << x << " is: " << finalAns << endl;

    return 0;
}