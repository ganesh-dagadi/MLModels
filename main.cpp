#include "./models/LinearRegression.cpp"
#include <vector>
int main(){
    LogisticRegression lr;
    vector<double> x = {10.0 , 20.0 , 30.0 , 40.0 , 50.0 , 60.0};
    vector<double> y = {0.0 , 0.0 , 0.0 , 1.0 , 1.0 , 1.0};
    lr.fit(x ,y);
    cout << " \n" << lr.predict(100.0) << " \n";
}