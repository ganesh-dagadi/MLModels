#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class LinearRegression{
    private:
    double w = 0.01;
    double b = 0.01;
    double alph = 0.001;
    // double stopCost = 0.0000000000001;
    int epochs = 10000;
    vector<double> x;
    vector<double> y;
    double predict(double x){
        //cout << "predicting" << (this->w * x) + this->b << "\n";
        return (this->w * x) + this->b;
        
    }

    double dowJ_dowW(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss += (predict(x[i]) - y[i]) * x[i]; 
           // cout << "total loss is" << totalLoss << endl;
        }
        //cout << " \n returning dj/dw" << totalLoss/(double)x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    double dowJ_dowB(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss += (predict(x[i]) - y[i]); 
        }
        //cout << "\n returning dj/db" << totalLoss/x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    double getCost(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss +=  pow(predict(x[i]) - y[i] , 2);
        }
        //cout << "current cost is " << totalLoss/x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    void gradientDescent(){
        int currentEpoch = 0;
        double prevCost = 0;
        double currCost = getCost(this->x , this->y);
        double tempW = w;
        double tempB = b;
        while(currentEpoch < epochs){ //&& (currCost - prevCost) > stopCost
            tempW = w - alph * dowJ_dowW(x , y);
            tempB = b - alph * (dowJ_dowB(x , y));
            cout << tempW << " " << tempB << endl;
            w = tempW;
            b = tempB;
            prevCost = currCost;
            currCost = getCost(x , y);
            currentEpoch++;
        }
    }
    public:
    void fit(vector<double> x , vector<double> y){
        this->x = x;
        this->y = y;
        gradientDescent();
        cout << "set w to" << w << " b to " << b;
    }
};

class LogisticRegression{
    private:
    double w = 0.01;
    double b = 0.01;
    double alph = 0.001;
    // double stopCost = 0.0000000000001;
    int epochs = 10000;
    vector<double> x;
    vector<double> y;
    

    double dowJ_dowW(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss += x[i] * (y[i] - predict(x[i]));
           // cout << "total loss is" << totalLoss << endl;
        }
        //cout << " \n returning dj/dw" << totalLoss/(double)x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    double dowJ_dowB(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss += (y[i] - predict(x[i])); 
        }
        //cout << "\n returning dj/db" << totalLoss/x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    double getCost(vector<double> x , vector<double> y){
        double totalLoss = 0;
        for(int i = 0 ; i < x.size() ; i++){
            totalLoss += ((double)-1 * y[i]) * (log10(predict(x[i]))) - ((double)1-y[i]) * log10((double)1 - predict(x[i]));
        }
        //cout << "current cost is " << totalLoss/x.size() << "\n";
        return totalLoss/(double)x.size();
    }

    void gradientDescent(){
        int currentEpoch = 0;
        double prevCost = 0;
        double currCost = getCost(this->x , this->y);
        double tempW = w;
        double tempB = b;
        while(currentEpoch < epochs){ //&& (currCost - prevCost) > stopCost
            tempW = w - alph * dowJ_dowW(x , y);
            tempB = b - alph * (dowJ_dowB(x , y));
            cout << tempW << " " << tempB << endl;
            w = tempW;
            b = tempB;
            prevCost = currCost;
            currCost = getCost(x , y);
            currentEpoch++;
        }
    }
    public:
    void fit(vector<double> x , vector<double> y){
        this->x = x;
        this->y = y;
        gradientDescent();
        cout << "set w to" << w << " b to " << b;
    }

    double predict(double x){
        //cout << "predicting" << (this->w * x) + this->b << "\n";
        return 1/(1 + pow((double)2.718 , w*x + b));
    }

};